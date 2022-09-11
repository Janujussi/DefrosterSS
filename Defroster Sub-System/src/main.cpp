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

/* Radio Pins */
const uint8_t CE_PIN = 7;
const uint8_t CSN_PIN = 8;

/* Heating Front End Pins */
const uint8_t FAN = 9;
const uint8_t HEATER = 10;
const uint8_t THERMOSTAT = 11;


/**************************************************************************
 *************************** Global Variables *****************************
 **************************************************************************/

/* Global variable which contains all information for defroster sub-system. */
DefrosterSS DefSSGHandle;

/* nRF24L01 */
RF24 radio(CE_PIN, CSN_PIN);

/* Message to keychain fob */
char* radioMSG;

void setup() {
	DefrosterSS_Init_Parameters(DefSSGHandle);
	DefrosterSS_System_Init();
	DefrosterSS_System_Configuration(DefSSGHandle);
	DefrosterSS_Transceiver_Init(radio);
}

void loop() {
  // put your main code here, to run repeatedly:
}