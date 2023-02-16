
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Define constants for servo motors
#define SHOULDER_SERVO 0
#define ELBOW_SERVO 1
#define WRIST_SERVO 2
#define GRIPPER_SERVO 3

// Define variables to store current servo positions
int shoulderPos = 90;
int elbowPos = 90;
int wristPos = 90;
int gripperPos = 20;

// Initialize Adafruit PWM servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  // Set PWM frequency to 60 Hz (standard for most servos)
  pwm.begin();
  pwm.setPWMFreq(60);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Wait for input from serial monitor
  while (!Serial.available());

  // Read input from serial monitor and move robot arm accordingly
  int shelfNum = Serial.parseInt();
  moveArmToShelf(shelfNum);
}

void moveArmToShelf(int shelfNum) {
  // Calculate servo positions based on selected shelf number
  switch (shelfNum) {
    case 1:
      shoulderPos = 60;
      elbowPos = 110;
      wristPos = 30;
      break;
    case 2:
      shoulderPos = 90;
      elbowPos = 90;
      wristPos = 60;
      break;
    case 3:
      shoulderPos = 120;
      elbowPos = 70;
      wristPos = 90;
      break;
    case 4:
      shoulderPos = 150;
      elbowPos = 50;
      wristPos = 120;
      break;
    default:
      Serial.println("Invalid shelf number.");
      return;
  }

  // Move servos to new positions
  pwm.setPWM(SHOULDER_SERVO, 0, shoulderPos);
  pwm.setPWM(ELBOW_SERVO, 0, elbowPos);
  pwm.setPWM(WRIST_SERVO, 0, wristPos);

  // Wait for servo movement to complete
  delay(500);

  // Open gripper and wait for it to fully open
  pwm.setPWM(GRIPPER_SERVO, 0, 30);
  delay(500);

  // Close gripper and wait for it to fully close
  pwm.setPWM(GRIPPER_SERVO, 0, 90);
  delay(500);

  // Move arm back to starting position
  pwm.setPWM(SHOULDER_SERVO, 0, 90);
  pwm.setPWM(ELBOW_SERVO, 0, 90);
  pwm.setPWM(WRIST_SERVO, 0, 90);
}

