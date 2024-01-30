#include <BluetoothSerial.h> // by Henry Abrahamsen

BluetoothSerial SerialBT;

const int ledPin = 2; // GPIO pin for the LED

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_LED"); // Bluetooth device name
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH); // Turn ON the LED
    } else if (command == '0') {
      digitalWrite(ledPin, LOW); // Turn OFF the LED
    }
  }
}
