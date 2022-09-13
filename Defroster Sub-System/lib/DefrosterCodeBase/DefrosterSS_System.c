
/** FILE: DefrosterSS_System.c
 *
 * @brief Implementation of all system functions of the defroster sub-system.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* Header Include Files */
#include "DefrosterSS_System.h"

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

uint8_t DefrosterSS_System_Init_HW(
	void* handle,
	const uint8_t fan,
	const uint8_t heater,
	const uint8_t thermostat
) {
	DefrosterSS_HWObj* HWObj = (DefrosterSS_HWObj*) handle;
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

uint8_t DefrosterSS_System_Init_Params(void* handle) {
	DefrosterSS_CFGObj* CFGObj = (DefrosterSS_CFGObj*) handle;
	Power_Ctrl powerCFG = CFGObj->powerCFG;
	Temperature_Ctrl tempCFG = CFGObj->tempCFG;
	Timer_Ctrl timeCFG = CFGObj->timeCFG;

	/* Initialize fan*/
	if (powerCFG.powerMode = POWER_OFF) {

	}
}

uint8_t DefrosterSS_System_Configuration(void* handle);

void DefrosterSS_PowerUp_Parameters(void* handle) {
	DefrosterSS_CFGObj* CFGObj = (DefrosterSS_CFGObj*) handle;
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