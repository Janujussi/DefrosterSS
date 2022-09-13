/**
 * FILE: main.cpp
 *
 * @brief Main file for running defroster sub-system.
 */

/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/

/* DefrosterSS Include Files */
#include "DefrosterSS.h"
#include "DefrosterSS_Checks.h"
#include "DefrosterSS_Power.h"
#include "DefrosterSS_System.h"
#include "DefrosterSS_System.c"
#include "DefrosterSS_Temperature.h"
#include "DefrosterSS_Transceiver.h"

/* Peripheral Include Files */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/* General Include Files */
#include <Arduino.h>

/**************************************************************************
 *************************** Definitions **********************************
 **************************************************************************/

/* Analog Pin Definitions */
// #define PIN_A0 14;
// #define PIN_A1 15;
// #define PIN_A2 16;
// #define PIN_A3 17;
// #define PIN_A4 18;
// #define PIN_A5 19;

/* Radio Pins */
const uint8_t CE_PIN = 7;
const uint8_t CSN_PIN = 8;

/* Heating Front End Pins */
const uint8_t FAN = 9;
const uint8_t HEATER = 10;
const uint8_t THERMOSTAT = PIN_A0;


/**************************************************************************
 *************************** Global Variables *****************************
 **************************************************************************/

/* Global variable which contains all information for defroster sub-system. */
DefrosterSS DefSSGlobal;

/* nRF24L01 */
RF24 radio(CE_PIN, CSN_PIN);

/* Message to keychain fob */
char* radioMSG;

void setup() {
	Serial.begin(9600);

	Control_Handle ctrlHandle = DefSSGlobal.configurationObj.cfgHandle;
	DefrosterSS_PowerUp_Parameters(ctrlHandle);
	// DefrosterSS_System_Init();
	// DefrosterSS_System_Configuration();
	// DefrosterSS_Transceiver_Init(radio);
}

void loop() {
	delay(1000);
	Serial.println(DefSSGlobal.configurationObj.powerCFG.powerMode);
	Serial.println(DefSSGlobal.configurationObj.powerCFG.powerCFG);
	Serial.println(DefSSGlobal.configurationObj.timeCFG.durationSeconds);
	Serial.println();
}