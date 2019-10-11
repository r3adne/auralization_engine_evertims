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


inline float getCoeffForBand(int band, int numbands, float temperature_C, float pressure_atm, float humidity_ratio, int medium){
    float a;
    float f = getBand(band, numbands); // frequency, Hz
    float pa = pressure_atm * 101.325; // pressure in kPa
    float t = temperature_C + 273.15; // temperature, K
    float hr = humidity_ratio;



    float h = hr * (getPsat(medium) / pa);
    float frO = (pa / PR) * (24 + 40400.0 * h * ((0.02 + h)/(0.391 + h)));
    float frN = (pa / PR) * pow((t / T0), -0.5f) * (9 + 280 * h * exp(-4.170 * (pow((t/T0), -1.0f/3.0f) - 1.0f)));
    float z = 0.1068 * exp(-3352.0f / t) * pow(((frN + pow(f, 2.0f)) / frN), -1.0f);
    float y = pow((t/T0), (-5.0f / 2.0f)) * (0.01275 * exp(-2234.1 / t) * pow((frO + pow(f, 2.0f) ), -1.0f) + z);
    a = 8.686 * pow(f, 2.0f) * (1.84 * pow(10.0f, -11.0f) * pow((pa / PR), -1) * pow(t / T0, 0.5f)) + y; // dB/m

    return a; // in dB/m
}



#endif /* AirAbsorption_h */

