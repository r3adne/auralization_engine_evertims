//
//  AirAbsorption.h
//  EvertSE
//
//  Created by Zachary Lewis-Towbes on 10/10/19.
//

#ifndef AirAbsorption_h
#define AirAbsorption_h

#include <math.h>
#include <cmath>
#include <iostream>
#include <assert.h>

#define X 0.1151292546497022842009 // the x coefficient which shortens our air absorption formula.
#define PR 101.325 // atmospheric pressure at sea level
#define T0 293.15 // 20 deg


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
    // this gets the frequency in Hz of the current frequency band, which can be either 3 or 10 at the moment. That said, if I find new materials data with higher resolution this may change.
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
    public:

    AirAbsorption(int numbands, float temperature_C, float pressure_atm, float humidity_ratio, int medium); // CONSTRUCTOR

    float getCoeffForBand(int band, int numbands);

    void setMedium(int newMedium);
    void setTemperature(float temperature_C);
    void setPressure(float pressure_atm);
    void setHumidity(float humidity_ratio); // setHumidity sets h, depends on getPsat, depends on medium
    void setNumBands(int numbands);

    void update_h(); //   updates h based on          _medium, _pa
    void update_frO(); // updates frO based on        _pa, h
    void update_frN(); // updates frN vbased on       _t, _pa, h

    void update_z(int _numbands); // updates (z_10 || z_3) based on _t, frN
    void update_y(int _numbands); // updates (y_10 || y_3) based on _t, frO, z
    void update_a(int _numbands); // updates (a_10 || a_3) based on _pa, _t, y


    private:

    float coefficients_10[10] = {31.5, 63.0, 126.0, 252.0, 504.0, 1008.0, 2016.0, 4032.0, 8064.0, 16128.0};
    float coefficients_3[3] = {126.0, 1008.0, 16128.0}; // check this.
    float bands_10[10];
    float bands_3[3];
    int numbands = 3;

    float a_10[10]; // absorption in dB/m
    float a_3[3];

    float z_10[10]; // nonstatic, used to shorten calculation
    float z_3[3];
    float y_10[10]; // nonstatic, used to shorten calculation
    float y_3[3];

    float pa; // atmospheric pressure in kPa    // must update a, frN, frO, h; frN||frO->t, a->y, h->medium; y->z,
    float t; // temperature in K                // must update z, y, frN; y->frO, frN->h,
    float hr; // percentage humidity
    int medium = 0;

    float h; // molar humidity
    float frO; // relaxation frequency of Oxygen
    float frN; // relaxation frequency of Nitrogen
};



void AirAbsorption::update_h(){

}


//////////////////// CONSTRUCTOR /////////////////////
AirAbsorption::AirAbsorption(int newNumbands, float temperature_C, float pressure_atm, float humidity_ratio, int newMedium){
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
    ///////////// TODO: this^ //////////////////////

}



/////////////////////// MAIN EXTERNAL CALLBACK //////////////////////
float AirAbsorption::getCoeffForBand(int band, int numbands){
    assert ((band < numbands - 1) && (band >= 0));

    if (numbands == 10){
        return coefficients_10[band];
    }
    else if (numbands == 3){
        return coefficients_3[band];

    }
    return 0.0f; // this is, quite obviously, very bad. Please don't call me out, I will fix this entire callback later.
}

/////////////////// BEGIN SETTERS ////////////////////////////
void AirAbsorption::setMedium(int newMedium){
    assert(newMedium == 0);
    medium = newMedium;

    update_h();
    update_frN();
    update_frO();
    update_z(numbands);
    update_y(numbands);
    update_z(numbands);
}

void AirAbsorption::setTemperature(float temperature_C){
    t = temperature_C + 273.15;

    update_h();
    update_frN();
    update_frO();
    update_z(numbands);
    update_y(numbands);
    update_a(numbands);
}

void AirAbsorption::setPressure(float pressure_atm){
    pa = pressure_atm * 101.325;

    update_h();
    update_frN();
    update_frO();
    update_z(numbands);
    update_y(numbands);
    update_z(numbands);
}

void AirAbsorption::setHumidity(float humidity_ratio){
    hr = humidity_ratio;

    update_h();
    update_frN();
    update_frO();
    update_z(numbands);
    update_y(numbands);
    update_z(numbands);
}

void AirAbsorption::setNumBands(int newNumbands){
    // ah, much better.
    assert (newNumbands == 3 || newNumbands == 10);
    numbands = newNumbands;

    // we must update everything which takes frequency, but we need not update h, frN, or frO.
    update_z(newNumbands);
    update_y(newNumbands);
    update_a(newNumbands);
}
///////////////// END SETTERS /////////////////////////


//////////////// BEGIN UPDATERS //////////////////////
void AirAbsorption::update_frN(){
    update_h(); // updates medium
    frN = (pa / PR) * pow((t / T0), -0.5f) * (9 + 280 * h * exp(-4.170 * (pow((t/T0), -1.0f/3.0f) - 1.0f))); // sensitivve to pa, t, hr
}

void AirAbsorption::update_y(int _numbands){
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


void AirAbsorption::update_z(int _numbands){
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

void AirAbsorption::update_a(int _numbands){
    update_z(_numbands);
    update_y(_numbands);

    if (_numbands == 10){
        for (int i=0; i < _numbands; i++){
            a_10[i] = 8.686 * pow(bands_10[i], 2.0f) * (1.84 * pow(10.0f, -11.0f) * pow((pa / PR), -1) * pow(t / T0, 0.5f)) + y_10[i]; // dB/m
        }
    }
    else if (_numbands == 3){
        for (int i=0; i < _numbands; i++){
        a_3[i] = 8.686 * pow(bands_3[i], 2.0f) * (1.84 * pow(10.0f, -11.0f) * pow((pa / PR), -1) * pow(t / T0, 0.5f)) + y_3[i]; // dB/m
        }
    }
}


//////////////// END UPDATERS //////////////////////////

#endif /* AirAbsorption_h */

//
//inline float getCoeffForBand(int band, int numbands, float temperature_C, float pressure_atm, float humidity_ratio, int medium){
//    float a;
//    float f = getBand(band, numbands); // frequency, Hz
//    float pa = pressure_atm * 101.325; // pressure in kPa
//    float t = temperature_C + 273.15; // temperature, K
//    float hr = humidity_ratio;
//
//
//
//    float h = hr * (getPsat(medium) / pa); // sensitive to: hr, medium, pa
//    float frO = (pa / PR) * (24 + 40400.0 * h * ((0.02 + h)/(0.391 + h))); // sensitive to: hr, pa
//    float frN = (pa / PR) * pow((t / T0), -0.5f) * (9 + 280 * h * exp(-4.170 * (pow((t/T0), -1.0f/3.0f) - 1.0f))); // sensitivve to pa, t, hr
//
//    float z = 0.1068 * exp(-3352.0f / t) * pow(((frN + pow(f, 2.0f)) / frN), -1.0f); // sensitive to: t, pa, hr ///////// possibly make a vector based on f
//    float y = pow((t/T0), (-5.0f / 2.0f)) * (0.01275 * exp(-2234.1 / t) * pow((frO + pow(f, 2.0f) ), -1.0f) + z); // sensitive to t, , pa, hr ///////// possibly make a vector based on f
//
//    a = 8.686 * pow(f, 2.0f) * (1.84 * pow(10.0f, -11.0f) * pow((pa / PR), -1) * pow(t / T0, 0.5f)) + y; // dB/m
//
//    return a; // in dB/m
//}
