#include <WiFi.h>
#include <HTTPClient.h>

#define LINE_ACCESS_TOKEN "...."
#define ssid "Wokwi-GUEST"
#define password ""

// Replace with the user ID of the LINE user or group to which you want to send a message
const String userId = "...";  // You need to get this ID from the LINE bot setup

const char* lineMessagingUrl = "https://api.line.me/v2/bot/message/push";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  sendLineMessage("Message Text!");
}

void loop() {
  // Nothing in loop for this test
}

void sendLineMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(lineMessagingUrl);
    http.addHeader("Authorization", "Bearer " + String(LINE_ACCESS_TOKEN));
    http.addHeader("Content-Type", "application/json");

    String postData = "{\"to\": \"" + userId + "\", \"messages\": [{\"type\": \"text\", \"text\": \"" + message + "\"}]}";
    
    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("LINE API Response: " + response);
    } else {
      Serial.println("Error code: " + String(httpResponseCode));
    }

    http.end();
  } else {
    Serial.println("Error: Not connected to WiFi");
  }
}