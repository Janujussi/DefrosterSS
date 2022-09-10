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
#include "DefrosterSS_Temperature.h"
#include "DefrosterSS_Transceiver.h"

/* Peripheral Include Files */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/* General Include Files */
#include <Arduino.h>

/**************************************************************************
 *************************** Definitions *****************************
 **************************************************************************/

/* Radio Pins */
#define CE_PIN 7
#define CSN_PIN 8

/* Heaating Front End Pins */
#define FAN 9
#define HEATER 10
#define THERMOSTAT 11

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
  DefrosterSS_Transceiver_Init(radio);
}

void loop() {
  // put your main code here, to run repeatedly:
}