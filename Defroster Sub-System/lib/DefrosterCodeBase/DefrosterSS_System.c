
/** FILE: DefrosterSS_System.c
 *
 * @brief Implementation of all system functions of the defroster sub-system.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* DefrosterSS Include Files */
#include "DefrosterSS_System.h"

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

uint8_t DefrosterSS_System_Init_HW(
	DefrosterSS_HWObj* HWObj,
	const uint8_t fan,
	const uint8_t heater,
	const uint8_t thermostat
) {
	uint8_t FAN_PIN = HWObj->FAN_PIN;
	uint8_t HEATER_PIN = HWObj->HEATER_PIN;
	uint8_t THERMOSTAT_PIN = HWObj->safetyMeasureObj.THERMOSTAT_PIN;

	/* Assign HW Pins */
	FAN_PIN = fan;
	HEATER_PIN = heater;
	THERMOSTAT_PIN = thermostat;

	pinMode(FAN_PIN, OUTPUT);
	pinMode(HEATER_PIN, OUTPUT);
}

uint8_t DefrosterSS_System_Init_Params(DefrosterSS_CFGObj* CFGObj, DefrosterSS_HWObj HWObj) {
	Power_Ctrl powerCFG = CFGObj->powerCFG;
	Temperature_Ctrl tempCFG = CFGObj->tempCFG;
	Timer_Ctrl timeCFG = CFGObj->timeCFG;

	/* Initialize power settings*/
	if (powerCFG.powerMode == POWER_ON) {
		switch(tempCFG.tempMode) {
			case TEMP_LOW: {
				analogWrite(HWObj.FAN_PIN, 100)
				break;
			}
			case TEMP_MEDIUM: {
				analogWrite(HWObj.FAN_PIN, 175)
				break;
			}
			case TEMP_HIGH: {
				analogWrite(HWObj.FAN_PIN, 255)
				break;
			}
			case default: {
				analogWrite(HWObj.FAN_PIN, 255)
				break;
			}
		}

		if (powerCFG.powerCFG == POWER_DEFAULT) {
			switch(tempCFG.tempMode) {
				case TEMP_LOW: {
					analogWrite(HWObj.HEATER_PIN, 100)
						}
				
				case TEMP_MEDIUM: {
					analogWrite(HWObj.HEATER_PIN, 175)
					break;
				}
				case TEMP_HIGH: {
					analogWrite(HWObj.HEATER_PIN, 255)
					break;
				}
				case default: {
					analogWrite(HWObj.HEATER_PIN, 255)
					break;
				}
			}
		}
	} else {
		digitalWrite(HWObj.FAN_PIN, LOW);
		digitalWrite(HWObj.HEATER_PIN, LOW);
	}

	/* Initialize timer settings */
	if (timeCFG.timerMode == TIMER_CUSTOM) {
//---------------------------------------
	}
}

uint8_t DefrosterSS_System_Configuration(void* handle);

void DefrosterSS_PowerUp_Parameters(DefrosterSS_CFGObj* CFGObj) {
	Power_Ctrl powerCFG = CFGObj->powerCFG;
	Temperature_Ctrl tempCFG = CFGObj->tempCFG;
	Timer_Ctrl timeCFG = CFGObj->timeCFG;

	/* Power Settings */
	powerCFG.powerMode = POWER_OFF;
	powerCFG.powerCFG = POWER_DEFAULT;

	/* Temperature Settings */
	tempCFG.tempMode = TEMP_DEFAULT;

	/* Timer Settings */
	timeCFG.durationSeconds = 900;	// 15 minutes
	timeCFG.timerMode = TIMER_DEFAULT;
}