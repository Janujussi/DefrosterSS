
/** FILE: DefrosterSS_System.c
 *
 * @brief Implementation of all system functions of the defroster sub-system.
*/

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* DefrosterSS Include Files */
#include "DefrosterSS_System.h"
#include "DefrosterSS_Power.cpp"

/**************************************************************************
 *************************** Functions ************************************
 **************************************************************************/

void DefrosterSS_System_Init_HW(
	DefrosterSS_HWObj* HWObj,
	const uint8_t fan,
	const uint8_t heater,
	const uint8_t thermostat
) {
	uint8_t* FAN_PIN = &HWObj->FAN_PIN;
	uint8_t* HEATER_PIN = &HWObj->HEATER_PIN;
	uint8_t* THERMOSTAT_PIN = &HWObj->safetyMeasureObj.THERMOSTAT_PIN;

	/* Assign HW Pins */
	*FAN_PIN = fan;
	*HEATER_PIN = heater;
	*THERMOSTAT_PIN = thermostat;

	pinMode(*FAN_PIN, OUTPUT);
	pinMode(*HEATER_PIN, OUTPUT);
}

void DefrosterSS_System_Init_Params(DefrosterSS_CFGObj CFGObj, DefrosterSS_HWObj HWObj) {
	Power_Ctrl powerCFG = CFGObj.powerCFG;
	Temperature_Ctrl tempCFG = CFGObj.tempCFG;
	Timer_Ctrl timeCFG = CFGObj.timeCFG;
	uint8_t FAN_PIN = HWObj.FAN_PIN;
	uint8_t HEATER_PIN = HWObj.HEATER_PIN;

	/* Initialize power settings*/
	if (powerCFG.powerMode == POWER_ON) {
		DefrosterSS_fanPowerOn(FAN_PIN, tempCFG.tempMode);

		if (powerCFG.powerCFG == POWER_DEFAULT) {	// Fan & heating
			DefrosterSS_heatPowerOn(HEATER_PIN, tempCFG.tempMode);
		}
	} else {	// Power off
		DefrosterSS_fanPowerOff(FAN_PIN);
		DefrosterSS_fanPowerOff(HEATER_PIN);
	}
}

void DefrosterSS_System_Configure(DefrosterSS_CFGObj* handle);

void DefrosterSS_PowerUp_Parameters(DefrosterSS_CFGObj* CFGObj) {
	Power_Ctrl* powerCFG = &CFGObj->powerCFG;
	Temperature_Ctrl* tempCFG = &CFGObj->tempCFG;
	Timer_Ctrl* timeCFG = &CFGObj->timeCFG;

	/* Power Settings */
	powerCFG->powerMode = POWER_ON;
	powerCFG->powerCFG = POWER_DEFAULT;

	/* Temperature Settings */
	tempCFG->tempMode = TEMP_DEFAULT;

	/* Timer Settings */
	timeCFG->durationSeconds = 15;	// 15 minutes
	timeCFG->timerMode = TIMER_DEFAULT;
}