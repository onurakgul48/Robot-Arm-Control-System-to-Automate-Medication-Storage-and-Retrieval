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
int gripperPos = 40;

// Define constants for servo calibration
#define SERVOMIN 150
#define SERVOMAX 600
 
// Initialize Adafruit PWM servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Function prototypes
void moveArmToShelf(int shelfNum);
void moveArmToCounter(int counterPos);
void homePosition();

void setup() {

  // Set PWM frequency to 60 Hz (standard for most servos)
  pwm.begin();
  pwm.setPWMFreq(60);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Wait for input from serial monitor
  if (Serial.available() > 0) {
    char command = Serial.read();
    // Move arm to home position
    if (command == 'H') {
      homePosition();
    }
    // Move arm to selected shelf
    if (command >= '1' && command <= '4') {
      int shelfNum = command - '0';
      moveArmToShelf(shelfNum);
      // Wait for input from serial monitor
      while (Serial.available() == 0) {}
      // Move arm to counter position
      int counterPos = Serial.parseInt();
      moveArmToCounter(counterPos);
    }

  }

}


 
void moveArmToShelf(int shelfNum) {
  // Check if shelf number is valid
  if (shelfNum >= 1 && shelfNum <= 4) {
    // Calculate servo positions based on selected shelf number
    switch (shelfNum) {
      case 1:
        shoulderPos = 30;
        elbowPos = 90;
        wristPos = 0;
        break;

      case 2:
        shoulderPos = 30;
        elbowPos = 90;
        wristPos = 50;
        break;

      case 3:
        shoulderPos = 140;
        elbowPos = 30;
        wristPos = 60;
        break;

      case 4:
        shoulderPos = 140;
        elbowPos = 30;
        wristPos = 0;
        break;
    }

    Serial.println("Moving to shelf.");
  } else {
    Serial.println("Please enter a valid shelf number. (1-4)");
  }
}

void moveArmToCounter(int counterPos) {

// Move the arm to the counter position
int shoulderCounterPos = 90;
int elbowCounterPos = 50;
int wristCounterPos = 40;

// Map servo positions to the calibrated range
int shoulderCounterPWM = map(shoulderCounterPos, 0, 180, SERVOMIN, SERVOMAX);
int elbowCounterPWM = map(elbowCounterPos, 0, 180, SERVOMIN, SERVOMAX);
int wristCounterPWM = map(wristCounterPos, 0, 180, SERVOMIN, SERVOMAX);

// Move the arm to the counter position
pwm.setPWM(ELBOW_SERVO, 0, elbowCounterPWM);
delay(1000);
pwm.setPWM(WRIST_SERVO, 0, wristCounterPWM);
pwm.setPWM(SHOULDER_SERVO, 0, shoulderCounterPWM);

// Wait for the arm to reach the counter
delay(1000);
// Open the gripper to drop the medicine
pwm.setPWM(GRIPPER_SERVO, 0, map(90, 0, 180, SERVOMIN, SERVOMAX));
delay(500);

// Wait for the gripper to fully open
delay(300);

// Close the gripper
pwm.setPWM(GRIPPER_SERVO, 0, map(gripperPos, 0, 180, SERVOMIN, SERVOMAX));

// Wait for the gripper to fully close
delay(300);

// Return the arm to the home position

shoulderPos = 90;
elbowPos = 90;
wristPos = 90;

// Map servo positions to the calibrated range
int shoulderHomePWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
int elbowHomePWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
int wristHomePWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);

// Move the arm to the home position
pwm.setPWM(SHOULDER_SERVO, 0, shoulderHomePWM);
delay(500);
pwm.setPWM(ELBOW_SERVO, 0, elbowHomePWM);
pwm.setPWM(WRIST_SERVO, 0, wristHomePWM);

// Wait for the arm to reach the home position
delay(1000);
}

void homePosition() {
// Move the arm to the home position
shoulderPos = 90;
elbowPos = 90;
wristPos = 90;

// Map servo positions to the calibrated range
int shoulderHomePWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
int elbowHomePWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
int wristHomePWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);

// Move the arm to the home position
pwm.setPWM(SHOULDER_SERVO, 0, shoulderHomePWM);
delay(500);
pwm.setPWM(ELBOW_SERVO, 0, elbowHomePWM);
pwm.setPWM(WRIST_SERVO, 0, wristHomePWM);
 
// Wait for the arm to reach the home position
delay(1000);
}

void homePosition() {

// Return the arm to the home position
shoulderPos = 90;
elbowPos = 90;
wristPos = 90;
gripperPos = 40;

// Map servo positions to the calibrated range

int shoulderHomePWM = map(shoulderPos, 0, 180, SERVOMIN, SERVOMAX);
int elbowHomePWM = map(elbowPos, 0, 180, SERVOMIN, SERVOMAX);
int wristHomePWM = map(wristPos, 0, 180, SERVOMIN, SERVOMAX);
int gripperHomePWM = map(gripperPos, 0, 180, SERVOMIN, SERVOMAX);


// Move the arm to the home position
pwm.setPWM(SHOULDER_SERVO, 0, shoulderHomePWM);
delay(500);
pwm.setPWM(ELBOW_SERVO, 0, elbowHomePWM);
pwm.setPWM(WRIST_SERVO, 0, wristHomePWM);
pwm.setPWM(GRIPPER_SERVO, 0, gripperHomePWM);

 
// Wait for the arm to reach the home position
delay(1000);
Serial.println("Arm is in home position.");