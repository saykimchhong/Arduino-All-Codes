#include <WiFiManager.h>

#define WIFI_RESET_PIN 4  // Replace with the GPIO pin connected to the WiFi reset button
#define LONG_PRESS_DURATION 5000  // 5 seconds in milliseconds

unsigned long buttonPressStartTime = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(WIFI_RESET_PIN, INPUT_PULLUP);

  // Check if the WiFi reset button is pressed during boot
  if (digitalRead(WIFI_RESET_PIN) == LOW) {
    Serial.println("WiFi reset button pressed during boot. Clearing WiFi settings.");
    WiFiManager wifiManager;
    wifiManager.resetSettings();
  }

  // Rest of your setup code
}

void loop() {
  // Check if the WiFi reset button is pressed and measure the duration
  if (digitalRead(WIFI_RESET_PIN) == LOW) {
    if (buttonPressStartTime == 0) {
      // Record the start time of the button press
      buttonPressStartTime = millis();
    }

    // Check if the button has been pressed for at least LONG_PRESS_DURATION
    if (millis() - buttonPressStartTime >= LONG_PRESS_DURATION) {
      Serial.println("WiFi reset button pressed for 5 seconds. Clearing WiFi settings.");
      WiFiManager wifiManager;
      wifiManager.resetSettings();
      
      // Reset the button press start time to avoid repeated actions
      buttonPressStartTime = 0;
    }
  } else {
    // Reset the button press start time when the button is released
    buttonPressStartTime = 0;
  }

  // Your main code goes here
}
