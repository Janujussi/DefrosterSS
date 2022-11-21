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
#include "DefrosterSS_System.cpp"
#include "DefrosterSS_Transceiver.h"
#include "DefrosterSS_Transceiver.cpp"
#include "DefrosterSS_Timer.h"
#include "DefrosterSS_Timer.c"

/* Peripheral Include Files */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/* General Include Files */
#include <Arduino.h>

/**************************************************************************
 *************************** Definitions **********************************
 **************************************************************************/
uint16_t getPowerDuration();

/* Radio Pins */
const uint8_t CE_PIN = 9;
const uint8_t CSN_PIN = 8;

/* Heating Front End Pins */
const uint8_t FAN = 5;
const uint8_t HEATER = 7;
const uint8_t THERMOSTAT = PIN_A0;
const uint8_t THERMISTOR_ENABLE = 4;

static uint16_t radioTick = 0;
static uint16_t powerTick = 0;
static uint16_t tempTick = 0;

/**************************************************************************
 *************************** Global Variables *****************************
 **************************************************************************/

/* Global variable which contains all information for defroster sub-system. */
static DefrosterSS DefSSGlobal;

/* nRF24L01 */
static RF24 radio(CE_PIN, CSN_PIN);

/* Message to/from keychain fob */
static byte* receiveMSG;
static byte* sendMSG;
static byte offConfig[5] = {0x1, 0x0, 0x3, 0xF, 0x0};

void setup() {
	Serial.begin(9600);
	// radio.begin();

	// // Set listening address
	// radio.openReadingPipe(0, 0x00001);

	// // Set module as receiver
	// radio.startListening();

	DefrosterSS_Timer_SystemTimerConfiguration();
	DefrosterSS_PowerUp_Parameters(&DefSSGlobal.configurationObj);
	DefrosterSS_System_Init_HW(&DefSSGlobal.HWObj, FAN, HEATER, THERMOSTAT, THERMISTOR_ENABLE);
	DefrosterSS_System_Init_Params(DefSSGlobal.configurationObj, DefSSGlobal.HWObj);
	DefrosterSS_Transceiver_Init(radio);
	pinMode(THERMISTOR_ENABLE, OUTPUT);
}

void loop() {
	// if (radioTick >= 5) {
	// 	Serial.println("Checking for message");
	// 	if (radio.available()) {
	// 		Serial.println("Received message:");
	// 		receiveMSG = DefrosterSS_getMsg(radio);
	// 		for (int i = 0; i < 5; i++) {
	// 			Serial.println((int) receiveMSG[i]);
	// 		}
	// 		Serial.println();

	// 		DefrosterSS_System_Configure(&DefSSGlobal, receiveMSG);
	// 	}
	// 	radioTick = 0;
	// }

	if (radioTick >= 5) {
		Serial.println("Checking for message");
		Serial.print("radio availability: ");
		Serial.print(radio.available());
		Serial.println();
		if (radio.available()) {
			Serial.println("Received message:");
			receiveMSG = DefrosterSS_getMsg(radio);
			for (int i = 0; i < 5; i++) {
				Serial.println((int) receiveMSG[i]);
			}
			Serial.println();

			DefrosterSS_System_Configure(&DefSSGlobal, receiveMSG);
			DefrosterSS_Transceiver_Init(radio);
		}
		radioTick = 0;
	}

	if (powerTick >= getPowerDuration()) {
		DefrosterSS_System_Configure(&DefSSGlobal, offConfig);
		DefrosterSS_fanPowerOff(FAN);
		DefrosterSS_heatPowerOff(HEATER);
		Serial.println("power turned off");
		powerTick = 0;
		DefSSGlobal.configurationObj.timeCFG.durationSeconds = 100000;
	}

	if (tempTick >= 10) {
		uint16_t temperature = DefrosterSS_checkTemp(DefSSGlobal);

		if (temperature > 80) {
			DefrosterSS_System_Configure(&DefSSGlobal, offConfig);
			DefrosterSS_fanPowerOff(FAN);
			DefrosterSS_heatPowerOff(HEATER);
			Serial.println("temperature too hot, power turned off");
		}

		char buffer[3];
		itoa(temperature, buffer, 10);

		Serial.println("Temperature being sent:");
		for (int i = 0; i < 3; i++) {
			Serial.print(buffer[i]);
		}
		Serial.println();

		radio.stopListening();
		radio.openWritingPipe(0x00002);
		radio.write(&buffer, sizeof(buffer));
		radio.startListening();
		tempTick = 0;
	}
}

ISR(TIMER1_COMPA_vect) {
	TCNT1 = 0;	// Timer value reset
	radioTick++;
	powerTick++;
	tempTick++;
	Serial.print("Time left: ");
	Serial.print(getPowerDuration() - powerTick);
	Serial.println();
	Serial.println("powerCFG: ");
	Serial.println(DefSSGlobal.configurationObj.powerCFG.powerCFG);
	Serial.println("powerMode: ");
	Serial.println(DefSSGlobal.configurationObj.powerCFG.powerMode);
	Serial.println("tempMode: ");
	Serial.println(DefSSGlobal.configurationObj.tempCFG.tempMode);
}

uint16_t getPowerDuration() {
	return DefSSGlobal.configurationObj.timeCFG.durationSeconds;
}