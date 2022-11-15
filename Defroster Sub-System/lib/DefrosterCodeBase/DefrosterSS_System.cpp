
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
	const uint8_t thermostat,
	const uint8_t thermistor_enable
) {
	uint8_t* FAN_PIN = &(HWObj->FAN_PIN);
	uint8_t* HEATER_PIN = &(HWObj->HEATER_PIN);
	uint8_t* THERMOSTAT_PIN = &(HWObj->safetyMeasureObj.THERMOSTAT_PIN);
	uint8_t* THERMISTOR_ENABLE = &(HWObj->safetyMeasureObj.THERMISTOR_ENABLE);

	/* Assign HW Pins */
	*FAN_PIN = fan;
	*HEATER_PIN = heater;
	*THERMOSTAT_PIN = thermostat;
	*THERMISTOR_ENABLE = thermistor_enable;

	pinMode(*FAN_PIN, OUTPUT);
	pinMode(*HEATER_PIN, OUTPUT);
	pinMode(*THERMISTOR_ENABLE, OUTPUT);
}

void DefrosterSS_System_Init_Params(DefrosterSS_CFGObj CFGObj, DefrosterSS_HWObj HWObj) {
	Serial.println("Initializing settings)");
	Power_Ctrl powerCFG = CFGObj.powerCFG;
	uint8_t FAN_PIN = HWObj.FAN_PIN;
	uint8_t HEATER_PIN = HWObj.HEATER_PIN;

	/* Initialize power settings*/
	if (powerCFG.powerMode == POWER_ON) {
		DefrosterSS_fanPowerOn(FAN_PIN, TEMP_HIGH /*tempCFG.tempMode*/);

		if (powerCFG.powerCFG == POWER_DEFAULT) {	// Fan & heating
			DefrosterSS_heatPowerOn(HEATER_PIN, TEMP_HIGH /*tempCFG.tempMode*/);
		} else {
			DefrosterSS_heatPowerOff(HEATER_PIN);
		}
	} else {	// Power off
		DefrosterSS_fanPowerOff(FAN_PIN);
		DefrosterSS_heatPowerOff(HEATER_PIN);
	}
}

void DefrosterSS_System_Configure(DefrosterSS* handle, byte* buffer) {
	uint16_t time = 0x0000;

	Serial.println("Configuring settings.");

	handle->configurationObj.powerCFG.powerMode = (Power_Mode) buffer[0];
	handle->configurationObj.powerCFG.powerCFG = (Power_CFG) buffer[1];
	handle->configurationObj.tempCFG.tempMode = (Temperature_Mode) buffer[2];
	time = (buffer[3] << 4);
	time |= buffer[4];
	handle->configurationObj.timeCFG.durationSeconds = time;

	if (time == 0) {
		handle->configurationObj.timeCFG.durationSeconds = 900;
	}

	DefrosterSS_System_Init_Params(handle->configurationObj, handle->HWObj);
}

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
	timeCFG->durationSeconds = 300;	// 15 minutes
	timeCFG->timerMode = TIMER_DEFAULT;
}