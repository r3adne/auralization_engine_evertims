//
//  AirAbsorption.h
//  EvertSE
//
//  Created by Zachary Lewis-Towbes on 10/10/19.
//
#pragma once

#ifndef AirAbsorption_h
#define AirAbsorption_h

#include <math.h>
#include <cmath>
#include <iostream>
#include <assert.h>

#define X 0.1151292546497022842009 // the x coefficient which shortens our air absorption formula.
#define PR 101.325 // atmospheric pressure at sea level
#define T0 293.15 // 20 deg C
#define EPSILON 0.000000000000000000000001 // really small


inline float getPsat(int medium){
    if (medium == 0){
        // medium is air
        return 1.03; // kPa
    }
    else{
        //        cout << "unknown medium -- AirAbsorption.h" << '\n'; // TODO: make this print to log
        return NULL;
    }
}

inline float getBand(int band, int numbands){
    // this gets the frequency in Hz of the center of the current frequency band, which can be either 3 or 10 at the moment. That said, if I find new materials data with higher resolution this may change.
    if (numbands == 10){
        return 31.5 * pow(2, band);
    }
    else if (numbands == 3){
        float bands[3] = {480.0f, 4340.0f, 8200.0f};
        return bands[band];
    }
    else {
//        cout << numbands << "is an invalid number of bands \n";
        return 0.f;
    }

}


class AirAbsorption
{
    // attributes
    public:
        // nothing to see here
    private:

    float coefficients_10[10];
    float coefficients_3[3];
    float bands_10[10] = {31.5, 63.0, 126.0, 252.0, 504.0, 1008.0, 2016.0, 4032.0, 8064.0, 16128.0};
    float bands_3[3] = {126.0, 1008.0, 16128.0}; // check this.
    int numbands = 3;

    float a_10[10]; // absorption in dB/m
    float a_3[3];

    float z_10[10] = {0}; // nonstatic, used to shorten calculation
    float z_3[3] = {0};
    float y_10[10] = {0}; // nonstatic, used to shorten calculation
    float y_3[3] = {0};

    float pa = 101.325; // atmospheric pressure in kPa    // must update a, frN, frO, h; frN||frO->t, a->y, h->medium; y->z,
    float t = 20 + 273.15; // temperature in K                // must update z, y, frN; y->frO, frN->h,
    float hr = 0.5; // percentage humidity
    int medium = 0;

    float h; // molar humidity
    float frO; // relaxation frequency of Oxygen
    float frN; // relaxation frequency of Nitrogen


    /////////////////////////// METHODS ///////////////////////////
    public:

        // CONSTRUCTOR
        AirAbsorption(){};
    
        AirAbsorption(int newNumbands, float temperature_C, float pressure_atm, float humidity_ratio, int newMedium){
            // Parameterized constructor for AirAbsorption.

            // sanatize inputs ================
            assert (newNumbands == 10 || newNumbands == 3); // newNumbands must be either 10 or 3.
            assert (newMedium == 0); // for now, there is only one medium.


            // set values, convert units ===============
            numbands = newNumbands;
            t = temperature_C + 273.15;
            hr = humidity_ratio;
            pa = pressure_atm * 101.325;
            medium = newMedium;

            // update everything ==========================

            update_all(newNumbands);
        }

        // DESTRUCTOR
        ~AirAbsorption(){
            // do this
        }

        /////////////////////// MAIN EXTERNAL CALLBACK //////////////////////
        float getCoeffForBand(int band, int numbands){
            if (numbands == 10){
                return a_10[band];
            }
            else if (numbands == 3){
                return a_3[band];

            }
            return 0.0f; // this is, quite obviously, very bad. Please don't call me out, I will fix this entire callback later.
        }

        /////////////////// BEGIN SETTERS ////////////////////////////
        void setMedium(int newMedium){
            assert(newMedium == 0);
            medium = newMedium;

            update_all(numbands);
        }

        void setTemperature(float temperature_C){
            float val = temperature_C + 273.15;

            if (val >= -EPSILON && val <= EPSILON){
                t = val + EPSILON;
            }
            else {
                t = val;
            }

            update_all(numbands);
        }

        void setPressure(float pressure_atm){
            if (pressure_atm > -EPSILON && pressure_atm < EPSILON){
                if (pressure_atm < 0){
                    pa = (pressure_atm * 101.325) - EPSILON;
                }
                else{
                    pa = (pressure_atm * 101.325) + EPSILON;
                }
            }
            else{
                pa = pressure_atm * 101.325;
            }

            update_all(numbands);
        }

        void setHumidity(float humidity_ratio){
            hr = humidity_ratio;

            update_all(numbands);
            //    update_h();
            //    update_frN();
            //    update_frO();
            //    update_z(numbands);
            //    update_y(numbands);
            //    update_z(numbands);
        }

        void setNumBands(int newNumbands){
            // ah, much better.
            assert (newNumbands == 0 || newNumbands == 3 || newNumbands == 10);
            if (newNumbands == 0){}
            else{
                numbands = newNumbands;

                // we must update everything which takes frequency, but we need not update h, frN, or frO (yay, saving like 20 instructions)
                update_z(newNumbands);
                update_y(newNumbands);
                update_a(newNumbands);
            }
        }
        ///////////////// END SETTERS /////////////////////////

        //////////////// BEGIN UPDATERS //////////////////////
        void update_h(){
            h = hr * (getPsat(medium) / (pa)); ///// some bad NaN prevention here
        }

        void update_frN(){
            frN = (pa / PR) * pow((t / T0), -0.5f) * (9 + 280 * h * exp(-4.170 * (pow((t/T0), -1.0f/3.0f) - 1.0f))); // sensitivve to pa, t, hr
        }

        void update_frO(){
            frO = (pa / PR) * (24 + 40400.0 * h * ((0.02 + h) / (0.391 + h) + EPSILON)); ///// some bad NaN prevention here
        }

        void update_y(int _numbands){
            // sensitive to t, pa, hr
            if (_numbands == 10){
                for (int i=0; i < _numbands; i++){
                    y_10[i] = pow((t/T0), (-5.0f / 2.0f)) * (0.01275 * exp(-2234.1 / t) * pow((frO + pow(bands_10[i], 2.0f)), -1.0f) + z_10[i]);
                }
            }
            else if (_numbands == 3){
                for (int i=0; i < _numbands; i++){
                    y_3[i] = pow((t/T0), (-5.0f / 2.0f)) * (0.01275 * exp(-2234.1 / t) * pow((frO + pow(bands_3[i], 2.0f) ), -1.0f) + z_3[i]);
                }
            }
        }


        void update_z(int _numbands){
            if (_numbands == 10){
                for (int i=0; i < _numbands; i++){
                    z_10[i] = 0.1068 * exp(-3352.0f / t) * pow(((frN + pow(bands_10[i], 2.0f)) / frN), -1.0f);
                }
            }
            else if (_numbands == 3){
                for (int i=0; i < _numbands; i++){
                    z_3[i] = 0.1068 * exp(-3352.0f / t) * pow(((frN + pow(bands_3[i], 2.0f)) / frN), -1.0f);
                }
            }
        }

        void update_a(int _numbands){
            if (_numbands == 10){
                for (int i=0; i < _numbands; i++){
                    // see below
                    a_10[i] = 8.686 * pow(bands_10[i], 2.0f) * (1.84 * pow(10.0f, -11.0f) * pow((pa / PR) + EPSILON, -1) * pow(t / T0, 0.5f)) + y_10[i]; // dB/m
                }
            }
            else if (_numbands == 3){
                for (int i=0; i < _numbands; i++){
                    // watch pa = 0 -- 0 ^ -1 = +Inf
                    a_3[i] = 8.686 * pow(bands_3[i], 2.0f) * (1.84 * pow(10.0f, -11.0f) * pow((pa / PR) + EPSILON, -1) * pow(t / T0, 0.5f)) + y_3[i]; // dB/m
                }
            }
        }

        void update_all(int _numbands){
            
            update_h();
            update_frN();
            update_frO();
            update_z(numbands);
            update_y(numbands);
            update_a(numbands);
        }

        //////////////// END UPDATERS //////////////////////////

};
//
#endif /* AirAbsorption_h */
