# Robot Arm Control System to Automate Medication Storage and Retrieval

This project is designed to automate medication storage and retrieval using a 3 DOF robot arm controlled by an Arduino and Adafruit PWM servo drivers. The system includes 4 shelves in front of the robot arm, with each shelf containing different medicines. Users can select a shelf through the serial monitor and move the robot arm's end effector to the chosen shelf. Once the shelf is selected, the robot arm will pick up the medicine from the shelf and place it to counter.

![main](https://user-images.githubusercontent.com/74906633/225676263-bd911666-a0cc-48fe-b466-211224f74b41.jpg)

# Updated Version

This code is for a medication storage control system that allows a user to select a shelf and retrieve medication from it using a robot arm controlled by an Arduino board. The system has a graphical user interface (GUI) created using the tkinter library in Python.

The code starts by importing necessary libraries including Wire.h and Adafruit_PWMServoDriver.h for controlling the servo motors. It defines constants for the servo motors, variables to store the current servo positions, and constants for servo calibration. The Adafruit_PWMServoDriver is then initialized and serial communication is started.

The main loop of the program waits for input from the serial monitor. If the input is 'H', the robot arm is moved to its home position using the homePosition() function. If the input is a number from 1 to 4, the moveArmToShelf() function is called to move the arm to the selected shelf, and then the moveArmToCounter() function is called to move the arm to the counter position and drop the medication.

The moveArmToShelf() function takes the selected shelf number as an argument and calculates the servo positions based on the shelf number. The moveArmToCounter() function takes the counter position as an argument, moves the arm to the counter position, opens the gripper to drop the medication, waits for the gripper to fully open and then closes the gripper. Finally, it returns the arm to its home position.

The homePosition() function moves the arm to its home position by setting the servo positions to their initial values, mapping the servo positions to the calibrated range, and then moving the arm to the home position.

The GUI is then created using tkinter library. It includes buttons for each shelf, a log text box to display retrieval logs, a status label to show the current status of the system, and a reset button to move the robot arm to its home position. When a user clicks on a shelf button, the on_click() function is called which sends the selected shelf number to the Arduino board to move the arm to that shelf and retrieve the medication.

Overall, this code provides a complete solution for controlling a medication storage system using a robot arm and a GUI.

# Installation
To get started with this project, follow these steps:

Assemble the robot arm kit using screws and other necessary parts according to the application you would like to use.

Download and install the required libraries for the project.

Build the robot arm and connect the 4 MG966r servo motors to the Adafruit PWM servo driver.

Upload the code to the Arduino board and connect it to the Adafruit PWM servo driver.


# Circuit Diagram
![image](https://user-images.githubusercontent.com/74906633/216340708-62e8fdd7-924e-4be8-88bb-8b7cc910a274.png)

# User Manual

1. Upload the Arduino code to your Arduino board.
2. Connect the Arduino board to your computer.
3. Update the `COM_PORT` and `BAUD_RATE` in the Python script to match your Arduino board's settings.
4. Run the Python script to launch the graphical user interface (GUI).
5. Use the GUI to select a shelf and move the robot arm.


# User Interface
The user interface is designed to be user-friendly and intuitive. It allows users to easily control the robot arm and monitor its progress.
We can choose the shelf from the GUI program.
After selecting a shelf, the arm will pick up the medicine and place it on the counter.
There is also a home position button when is clicked robot arm will move to the Home position always.

The log will display messages such as "Retrieving medication from Shelf 1..." or "Robot arm moved to Home Position". These messages will be displayed in a text box on the GUI interface. The log will help the user keep track of the robot arm's actions and will provide a history of all medication retrieval events.

![GUI](https://user-images.githubusercontent.com/74906633/225002398-dacc2e9a-3b78-4db2-9df7-15e39e80b0a7.PNG)


# Contributing
If you'd like to contribute to this project, feel free to submit a pull request with your changes or open an issue if you encounter any problems.

# Next Step:
Including HMI in this project in 3D envoriment.

# License
This project is licensed under Creative Commons.




