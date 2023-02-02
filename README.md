# 3-DOF-Robot-Arm-
Robot Arm Control System to Automate Medication Storage and Retrieval!

I am designing a project of 3 DOF robot arm with  arduino, adafruit pwm servo drivers and 4 MG966r servo motoros i will make 6 shelfs in front of the arm  and put medicines inside each shelf i want to input a shelf by serial monitor and move my robot arm's end effector to chosen shelf. After I choose the shelf i want to pick it up and place it to counter . I have already downloaded required libraries , build my robot arm and connected my servos to adafruit PWM servo driver.

![image](https://user-images.githubusercontent.com/74906633/216340708-62e8fdd7-924e-4be8-88bb-8b7cc910a274.png)


#include <Adafruit_PWMServoDriver.h>

// Constants for minimum and maximum shelf numbers

const int MIN_SHELF = 1;

const int MAX_SHELF = 6;

// Constants for the gripper and each DOF of the robot arm

const int GRIPPER = 4;

const int SHOULDER = 0;

const int ELBOW = 1;

const int WRIST = 2;

// Constants for minimum and maximum pulse lengths

const int SERVOMIN = 150;

const int SERVOMAX = 600;

// Constants for shelf 7 servo angles

const int SHELF_7_SHOULDER_ANGLE = 180;

const int SHELF_7_ELBOW_ANGLE = 160;

const int SHELF_7_WRIST_ANGLE = 120;


// Servo angles for each DOF and the gripper

int shoulderAngle = 0;

int elbowAngle = 0;

int wristAngle = 0;

int gripperAngle = 0;


// Initialize Adafruit PWM Servo Driver object

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {

  // Initialize serial communication
  
  Serial.begin(9600);

  // Initialize PWM Servo Driver
  
  pwm.begin();
  
  pwm.setPWMFreq(60);
  
}

void loop() {

  // Read shelf number from serial buffer
  
  int shelfNumber = readShelfNumber();

  // Move arm to specified shelf
  
  if (shelfNumber != -1) {
  
    moveToShelf(shelfNumber);
    
    pickUpFromShelf();
    
    moveToShelf7();
    
    placeOnShelf7();
    
  }
  
}

// Function to read shelf number from serial buffer

int readShelfNumber() {

  // Delay for a few milliseconds to allow data to be fully transmitted
  
  delay(5);

  if (Serial.available() > 0) {
  
    // Read shelf number from serial buffer
    
    int shelfNumber = Serial.parseInt();

    // Validate shelf number
    
    if (shelfNumber >= MIN_SHELF && shelfNumber <= MAX_SHELF) {
    
      return shelfNumber;
      
    } else {
    
      // Return -1 if shelf number is invalid
      
      return -1;
      
    }
  }
  
  // Return -1 if no data is available
  
  return -1;
  
}

// Function to move arm to specified shelf

void moveToShelf(int shelfNumber) 

  // TODO: Calculate and set servo angles for the specified shelf number
  
}

// Function to pick up item from specified shelf

void pickUpFromShelf() {

  // TODO: Close gripper to pick up item from shelf
  
}

// Function to move arm to shelf 7

void moveToShelf7() {

  // TODO: Set servo angles for shelf 7
  
}

// Function to place item on shelf 7

void placeOnShelf7() {

  // TODO: Open gripper to place item on shelf 7
  
}
