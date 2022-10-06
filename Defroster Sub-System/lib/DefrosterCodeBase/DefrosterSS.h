/** FILE: DefrosterSS.h
 *
 * @brief Data structures for defroster sub-system.
*/

#ifndef DEFROSTERSS_H
#define DEFROSTERSS_H


/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* General Include Files */
#include <stdint.h>
#include <Arduino.h>

/**************************************************************************
 *************************** Type Definitions *****************************
 **************************************************************************/

typedef uint16_t Timer_Duration;
typedef const uint8_t THERMOSTAT_PIN;

/**************************************************************************
 *************************** Enums ****************************************
 **************************************************************************/

/**
 * @b Decription
 * @n
 * 	Power mode/state.
 */
typedef enum Power_Mode_t {
	POWER_ON,
	POWER_OFF
} Power_Mode;

/**
 * @b Decription
 * @n
 * 	Power configuration: where the power is being supplied to.
 */
typedef enum Power_CFG_t {
	POWER_DEFAULT,
	POWER_FAN_ONLY
} Power_CFG;

/**
 * @b Decription
 * @n
 * 	Temperature heat level.
 */
typedef enum Temperature_Mode_t {
	TEMP_DEFAULT,
	TEMP_LOW,
	TEMP_MEDIUM,
	TEMP_HIGH
} Temperature_Mode;

/**
 * @b Decription
 * @n
 * 	Time mode: defualt or user selected.
 */
typedef enum Timer_Mode_t {
	TIMER_DEFAULT,
	TIMER_CUSTOM
} Timer_Mode;

/**
 * @b Decription
 * @n
 * 	Error list.
 */
typedef enum Error_List_t {
	TRANSMISSION_FAILURE_ERR,
	MODE_CONTROL_ERR
} Error_List;

/**
 * @b Decription
 * @n
 * 	Keychain messages.
 */
typedef enum Keychain_Message_t {
	TURN_ON,
	TURN_OFF,
	TEMPERATURE_DEFAULT,
	TEMPERATURE_LOW,
	TEMPERATURE_MED,
	TEMPERATURE_HIGH,
	TIME_DEFAULT,
	TIME_SCHEDULED
} Keychain_Message;


/**************************************************************************
 *************************** Data Structs ******************************
 **************************************************************************/

/**
 * @b Decription
 * @n
 * 	Temperature control.
 */
typedef struct Temperature_Ctrl_t {
	Temperature_Mode tempMode;
} Temperature_Ctrl;

/**
 * @b Decription
 * @n
 * 	Timer control.
 */
typedef struct Timer_Ctrl_t {
	Timer_Mode timerMode;
	Timer_Duration durationSeconds;
} Timer_Ctrl;

/**
 * @b Decription
 * @n
 * 	Power control.
 */
typedef struct Power_Ctrl_t {
	Power_Mode powerMode;
	Power_CFG powerCFG;
} Power_Ctrl;

/**
 * @b Decription
 * @n
 * 	DefrosterSS configuration object.
 */
typedef struct DefrosterSS_CFGObj_t {
	Power_Ctrl powerCFG;
	Temperature_Ctrl tempCFG;
	Timer_Ctrl timeCFG;
} DefrosterSS_CFGObj;

/**
 * @b Description
 * @n
 * 	Heating front end object.
 */
typedef struct DefrosterSS_HeatingFEObj_t {
	Power_Ctrl power;
	Timer_Ctrl timer;
	Temperature_Ctrl temperature;
} DefrosterSS_HeatingFEObj;

/**
 * @b Description
 * @n
 * 	Defroster SW safety setup.
 */
typedef struct DefrosterSS_SafetyMeasureObj_t {
	uint8_t THERMOSTAT_PIN;
} DefrosterSS_SafetyMeasureObj;

typedef struct DefrosterSS_HWObj_t {
	uint8_t FAN_PIN;
	uint8_t HEATER_PIN;
	DefrosterSS_SafetyMeasureObj safetyMeasureObj;
} DefrosterSS_HWObj;

/**
 * @b Decription
 * @n
 * 	Global handle struct
 */
typedef struct DefrosterSS_t {
	DefrosterSS_HeatingFEObj heatingFEObj;
	DefrosterSS_CFGObj configurationObj;
	DefrosterSS_HWObj HWObj;
} DefrosterSS;

#endif