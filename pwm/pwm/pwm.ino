const int ledPin = 13;  // The GPIO pin to which your LED is connected
const int pwmChannel = 0;  // PWM channel (0-15 for ESP32)
const int pwmFrequency = 5000;  // PWM frequency in Hz
const int pwmResolution = 8;  // PWM resolution (8, 10, 12, 15 bits)

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Configure PWM
  ledcSetup(pwmChannel, pwmFrequency, pwmResolution);

  // Attach the PWM channel to the LED pin
  ledcAttachPin(ledPin, pwmChannel);
}

void loop() {
  // Fade in
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(pwmChannel, dutyCycle);
    delay(10);
  }

  // Fade out
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(pwmChannel, dutyCycle);
    delay(10);
  }
}
