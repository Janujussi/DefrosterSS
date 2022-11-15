
/** FILE: DefrosterSS_Checks.cpp
 *
 * @brief Implementation of DefrosterSS_Checks.h.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

#include "DefrosterSS_Power.h"
#include <Arduino.h>

/**************************************************************************
 *************************** Functions Implementations ********************
 **************************************************************************/

uint16_t DefrosterSS_checkTemp(DefrosterSS handle) {
    int Vo;
    float R1 = 82000;
    float logR2, R2, T;
    float c1 = 2.215680508e-03, c2 = 2.445998032e-04, c3 = 1.219705868e-07;
    const uint8_t THERMISTOR_ENABLE = handle.HWObj.safetyMeasureObj.THERMISTOR_ENABLE;
    const uint8_t THERMISTOR_PIN = handle.HWObj.safetyMeasureObj.THERMOSTAT_PIN;

    digitalWrite(THERMISTOR_ENABLE, HIGH);
    Vo = analogRead(THERMISTOR_PIN);
    digitalWrite(THERMISTOR_ENABLE, LOW);
    R2 = R1 / (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    T = T - 273.15 + 104;
    //  T = (T * 9.0)/ 5.0 + 32.0; 

    Serial.print("Temperature: "); 
    Serial.print(T);
    Serial.println(" C"); 

    return T;
}
