#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager

#define WIFI_RESET_PIN 4  // GPIO pin connected to the WiFi reset button
#define LONG_PRESS_DURATION 5000  // 5 seconds in milliseconds

unsigned long buttonPressStartTime = 0;
bool buttonHeld = false;
    
void setup() {
  Serial.begin(115200);
  
  pinMode(WIFI_RESET_PIN, INPUT_PULLUP);

  // Check if the WiFi reset button is pressed during boot
  if (digitalRead(WIFI_RESET_PIN) == LOW) {
    buttonPressStartTime = millis();
    while (digitalRead(WIFI_RESET_PIN) == LOW) {
      if (millis() - buttonPressStartTime >= LONG_PRESS_DURATION) {
        Serial.println("WiFi reset button held for 5 seconds during boot. Clearing WiFi settings.");
        WiFiManager wm;
        wm.resetSettings();
        delay(3000);  // Give some time for the settings to reset
        ESP.restart();
      }
    }
  }

  // WiFiManager initialization
  WiFiManager wm;

  // Attempt to auto-connect to Wi-Fi
  bool res;
  res = wm.autoConnect("AutoConnectAP");  // Start an AP named "AutoConnectAP" if connection fails
  
  if (!res) {
    Serial.println("Failed to connect");
  } else {
    Serial.println("Connected...yeey :)");
  }
}

void loop() {
  // Check if the WiFi reset button is pressed and measure the duration
  if (digitalRead(WIFI_RESET_PIN) == LOW) {
    if (!buttonHeld) {
      buttonPressStartTime = millis();
      buttonHeld = true;
    }

    // Check if the button has been pressed for at least LONG_PRESS_DURATION
    if (millis() - buttonPressStartTime >= LONG_PRESS_DURATION) {
      Serial.println("WiFi reset button held for 5 seconds. Clearing WiFi settings.");
      WiFiManager wm;
      wm.resetSettings();
      
      // Reset the button press start time to avoid repeated actions
      buttonPressStartTime = 0;
      buttonHeld = false;

      // Restart the ESP to start the configuration portal
      ESP.restart();
    }
  } else {
    // Reset the button press start time when the button is released
    buttonPressStartTime = 0;
    buttonHeld = false;
  }

  // Your main loop code goes here
}
