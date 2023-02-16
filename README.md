# Robot Arm Control System to Automate Medication Storage and Retrieval

This project is designed to automate medication storage and retrieval using a 3 DOF robot arm controlled by an Arduino and Adafruit PWM servo drivers. The system includes 4 shelves in front of the robot arm, with each shelf containing different medicines. Users can select a shelf through the serial monitor and move the robot arm's end effector to the chosen shelf. Once the shelf is selected, the robot arm will pick up the medicine from the shelf and place it in a known position.

# Installation
To get started with this project, follow these steps:

Assemble the robot arm kit using screws and other necessary parts according to the application you would like to use.

Download and install the required libraries for the project.

Build the robot arm and connect the 4 MG966r servo motors to the Adafruit PWM servo driver.

Upload the code to the Arduino board and connect it to the Adafruit PWM servo driver.


# Circuit Diagram
![image](https://user-images.githubusercontent.com/74906633/216340708-62e8fdd7-924e-4be8-88bb-8b7cc910a274.png)

# Usaer Manual
Power on the system and ensure that the Arduino board is connected to the computer via USB.

Open the Arduino IDE and navigate to the serial monitor.

Enter a number (1-4) to select a shelf for the robot arm to move to. Press enter.

Wait for the robot arm to move to the selected shelf.

Once the robot arm is in position, it will automatically pick up the medicine from the shelf and place it in a known position.

To select a different shelf, repeat steps 3-5.

# Contributing
If you'd like to contribute to this project, feel free to submit a pull request with your changes or open an issue if you encounter any problems.

# Next Step:
Including HMI in this project in 3D envoriment.

# License
This project is licensed under Creative Commons.




