/**
 * @file Read_Flow_Rate_and_Volume.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/FlowSensor-Arduino
 */

// #include <Arduino.h>
#include <FlowSensor.h>    // Install FlowSensor by hafidhh

// Sensor Type
// YFS201;
// YFB1;
// OF10ZAT;
// OF10ZZT;
// OF05ZAT;
// OF05ZZT;

#define type YFS201
#define pin 17 // pin -> interrupt pin

FlowSensor WaterSensor(type, pin);
unsigned long timebefore = 0; // Same type as millis()
unsigned long reset = 0;

// Uncomment if use ESP8266 and ESP32
void IRAM_ATTR count()
{
  WaterSensor.count();
}

// Comment if use ESP8266 and ESP32
// void count()
// {
// 	WaterSensor.count();
// }

void setup() {
	Serial.begin(115200);
	WaterSensor.begin(count);
}

void loop() {
	if (millis() - timebefore >= 1000)
	{
		WaterSensor.read();
		Serial.print("Flow rate (L/minute) : ");
		Serial.println(WaterSensor.getFlowRate_m());
		Serial.print("Volume (L) : ");
		Serial.println(WaterSensor.getVolume());
		timebefore = millis();
	}

  // Reset Volume
	if (millis() - reset >= 60000)
	{
		WaterSensor.resetVolume();
		reset = millis();
	}
}