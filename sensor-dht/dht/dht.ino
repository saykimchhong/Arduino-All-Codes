#include "DHT.h"
#define DHT22PIN 13


DHT dht(DHT22PIN, DHT22);

void setup() {

  Serial.println("Hello, ESP32!");

  Serial.begin(115200);
/* Start the DHT22 Sensor */
  dht.begin();
}

void loop() {
  delay(1000); // this speeetup code heds up the simulation

  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);
}
