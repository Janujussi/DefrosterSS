
/** FILE: DefrosterSS_Power.c
 *
 * @brief Implementation of DefrosterSS_Power.h.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

#include "DefrosterSS_Power.h"
#include <Arduino.h>

/**************************************************************************
 *************************** Functions Implementations ********************
 **************************************************************************/

void DefrosterSS_fanPowerOn(int8_t fan, Temperature_Mode tempMode) {
	Serial.println("fan powered on");

	switch(tempMode) {
		case TEMP_LOW: {
			analogWrite(fan, 100);
			break;
		}
		case TEMP_MEDIUM: {
			analogWrite(fan, 175);
			break;
		}
		case TEMP_HIGH: {
			analogWrite(fan, 255);
			break;
		}
		case TEMP_DEFAULT: {
			digitalWrite(fan, HIGH);
			// analogWrite(fan, 255);
			break;
		}
	}
}

void DefrosterSS_heatPowerOn(int8_t heat, Temperature_Mode tempMode) {
	Serial.println("heat powered on");

	switch(tempMode) {
		case TEMP_LOW: {
			analogWrite(heat, 100);
			break;
			}

		case TEMP_MEDIUM: {
			analogWrite(heat, 175);
			break;
		}
		case TEMP_HIGH: {
			analogWrite(heat, 255);
			break;
		}
		case TEMP_DEFAULT: {
			analogWrite(heat, 255);
			break;
		}
	}
}

void DefrosterSS_servoPowerOn(int8_t servo);

void DefrosterSS_fanPowerOff(int8_t fan) {
	Serial.println("fan powered off");
	digitalWrite(fan, LOW);
}

void DefrosterSS_heatPowerOff(int8_t heat) {
	Serial.println("heat powered off");
	digitalWrite(heat, LOW);
}

void DefrosterSS_servoPowerOff(int8_t servo);