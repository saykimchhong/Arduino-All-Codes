#include <AccelStepper.h> // by Mike

// Define the motor connections
#define MOTOR_PIN_STEP 2
#define MOTOR_PIN_DIR 14
#define MOTOR_PIN_EN 15

// Create an instance of AccelStepper
AccelStepper stepper(1, MOTOR_PIN_STEP, MOTOR_PIN_DIR);

void setup() {
  // Set up motor control pins
  pinMode(MOTOR_PIN_EN, OUTPUT);
  digitalWrite(MOTOR_PIN_EN, LOW); // Enable the motor

  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
}

void loop() {
  // Rotate the motor 200 steps in one direction
  stepper.move(200);
  stepper.runToPosition();

  delay(1000); // Pause for a second

  // Rotate the motor 200 steps in the opposite direction
  stepper.move(-200);
  stepper.runToPosition();

  delay(1000); // Pause for a second
}
