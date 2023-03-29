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
int wristPos = 140;
int gripperPos = 40;

// Define constants for servo calibration
#define SERVOMIN 150
#define SERVOMAX 600

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
  // Map the current servo positions to the calibrated range
  int shoulderPWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
  int elbowPWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
  int wristPWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);
  int gripperPWM = map(gripperPos, 0, 180, SERVOMIN, SERVOMAX);

  // Set the PWM signals for each servo
  pwm.setPWM(SHOULDER_SERVO, 0, shoulderPWM);
  pwm.setPWM(ELBOW_SERVO, 0, elbowPWM);
  pwm.setPWM(WRIST_SERVO, 0, wristPWM);
  pwm.setPWM(GRIPPER_SERVO, 0, gripperPWM);

  // Wait for input from serial monitor
  while (!Serial.available());

  // Read input from serial monitor
  char inputChar = Serial.read();
  
  if (inputChar == 'H') {
    moveArmToHome();
  } else {
    int shelfNum = inputChar - '0'; // Convert the character to integer
    int CounterDegrees = Serial.parseInt();

    // Call the moveArmToShelf, moveElbowAndWristUp, and moveArmToCounter functions with received arguments
    moveArmToShelf(shelfNum);
    moveElbowAndWristUp(); // Call the new function here
    moveArmToCounter(CounterDegrees);
  }
}

void moveArmToHome() {
  // Return the arm to the home position
  shoulderPos = 90;
  elbowPos = 90;
  wristPos = 140;

  // Map servo positions to the calibrated range
  int shoulderHomePWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
  int elbowHomePWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
  int wristHomePWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);

  // Move the arm to the home position
  pwm.setPWM(SHOULDER_SERVO, 0, shoulderHomePWM);
  pwm.setPWM(ELBOW_SERVO, 0, elbowHomePWM);
  pwm.setPWM(WRIST_SERVO, 0, wristHomePWM);

  // Wait for the arm to reach the home position
  delay(500);
}

void moveArmToShelf(int shelfNum) {
  // Calculate servo positions based on selected shelf number
  switch (shelfNum) {
    case 1:
      shoulderPos = 25;
      elbowPos = 40;
      wristPos = 70;
      break;
    case 2:
      shoulderPos = 50;
      elbowPos = 35;
      wristPos = 90;
      break;
    case 3:
      shoulderPos = 155;
      elbowPos = 40;
      wristPos = 70;
      break;
    case 4:
      shoulderPos = 135;
      elbowPos = 30;
      wristPos = 100;
      break;
    default:
      Serial.println("Invalid shelf number.");
      return;
  }

  // Map servo positions to the calibrated range
  int shoulderPWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
  int elbowPWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
  int wristPWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);
  int gripperPWM = map(gripperPos, 0, 180, SERVOMIN, SERVOMAX);

  // Move servos to new positions
  pwm.setPWM(SHOULDER_SERVO, 0, shoulderPWM);
  delay(500);
  pwm.setPWM(ELBOW_SERVO, 0, elbowPWM);
  pwm.setPWM(WRIST_SERVO, 0, wristPWM);

  // Wait for servo movement to complete
  delay(1000);

  // Close gripper and wait for it to fully close
  pwm.setPWM(GRIPPER_SERVO, 0, map(90, 0, 180, SERVOMIN, SERVOMAX));
  delay(300);

}
void moveElbowAndWristUp() {
  // Move the elbow and wrist up after picking up the medicine
  elbowPos = 90;
  wristPos = 140;
  int elbowUpPWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
  int wristUpPWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(ELBOW_SERVO, 0, elbowUpPWM);
  pwm.setPWM(WRIST_SERVO, 0, wristUpPWM);
  delay(500);
}


void moveArmToCounter(int CounterDegrees) {
  // Move the arm to the counter position
  int shoulderCounterPos = 90;
  int elbowCounterPos = 50;
  int wristCounterPos = 100;

  // Map servo positions to the calibrated range
  int shoulderCounterPWM = map(shoulderCounterPos, 0, 180, SERVOMIN, SERVOMAX);
  int elbowCounterPWM = map(elbowCounterPos, 0, 180, SERVOMIN, SERVOMAX);
  int wristCounterPWM = map(wristCounterPos, 0, 180, SERVOMIN, SERVOMAX);


  // Move the arm to the counter position
  delay(500);
  pwm.setPWM(SHOULDER_SERVO, 0, shoulderCounterPWM);
  pwm.setPWM(ELBOW_SERVO, 0, elbowCounterPWM);
  pwm.setPWM(WRIST_SERVO, 0, wristCounterPWM);

  // Wait for the arm to reach the counter
  delay(1000);

  // Open the gripper to drop the medicine
  pwm.setPWM(GRIPPER_SERVO, 0, map(40, 0, 180, SERVOMIN, SERVOMAX));
  delay(300);
// Return the arm to the home position
  shoulderPos = 90;
  elbowPos = 90;
  wristPos = 140;

  // Map servo positions to the calibrated range
  int shoulderHomePWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
  int elbowHomePWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
  int wristHomePWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);

  // Move the arm to the home position
  pwm.setPWM(SHOULDER_SERVO, 0, shoulderHomePWM);
  pwm.setPWM(ELBOW_SERVO, 0, elbowHomePWM);
  pwm.setPWM(WRIST_SERVO, 0, wristHomePWM);

  // Wait for the arm to reach the home position
  delay(500);
  
}
