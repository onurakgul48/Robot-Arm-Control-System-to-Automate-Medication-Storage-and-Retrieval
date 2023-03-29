import tkinter as tk
from tkinter import messagebox
import serial
from PIL import ImageTk, Image

# Constants
COM_PORT = 'COM3'
BAUD_RATE = 9600

# Create a serial connection to Arduino
ser = serial.Serial(COM_PORT, BAUD_RATE)

# Define the function to send the selected shelf to Arduino
def send_shelf(shelf):
    ser.write(shelf.encode())
    status_label.config(text=f"Retrieving medication from Shelf {shelf}...")    
    log_text.insert('end', f"Retrieving medication from Shelf {shelf}...\n")

# Define the function to handle the button click event
def on_click(shelf):
    send_shelf(shelf)
        # Add code to control the robot arm to pick up the item from the selected shelf and place it on the counter
        # For example:
        # ser.write('P'.encode()) # send command to Arduino to activate the robot arm's picking action
        # ser.write('D'.encode()) # send command to Arduino to activate the robot arm's delivery action

# Define the function to reset the robot arm to its initial position
def move_to_home_position():
    ser.write('H'.encode())
    status_label.config(text="Robot arm moved to Home Position")
    log_text.insert('end', "Robot arm moved to Home Position\n")

# Create a window and add buttons for each shelf
root = tk.Tk()
root.geometry('900x600')
root.title('Medication Storage Control System')
root.configure(bg='#34495A') # Use a consistent background color

# Load the image and create an ImageTk object
img = Image.open('C:\\Users\\Onur\\Desktop\\RobotArmPythonTries\\university_logo.png')
img = img.resize((200, 200))  # resize the image to 100x100 pixels
logo = ImageTk.PhotoImage(img)

# Create a label for the logo and place it at (10, 10)
logo_label = tk.Label(root, image=logo)
logo_label.place(x=670, y=550)

# Add title label
title_label = tk.Label(root, text='Medication Storage Control System', font=('Arial', 24, 'bold'), bg='#34495E', fg='white')
title_label.pack(pady=20)

# Add subtitle label
subtitle_label = tk.Label(root, text='Select the shelf to retrieve medication:', font=('Arial', 14), bg='#34495E', fg='white')
subtitle_label.pack(pady=10)

# Add buttons for each shelf
button_frame = tk.Frame(root, bg='#34495E')
button_frame.pack(pady=10)

btn_shelf1 = tk.Button(button_frame, text='Shelf 1', font=('Arial', 14), width=10, height=3, command=lambda: on_click('1'))
btn_shelf2 = tk.Button(button_frame, text='Shelf 2', font=('Arial', 14), width=10, height=3, command=lambda: on_click('2'))
btn_shelf3 = tk.Button(button_frame, text='Shelf 3', font=('Arial', 14), width=10,height=3, command=lambda: on_click('3'))
btn_shelf4 = tk.Button(button_frame, text='Shelf 4', font=('Arial', 14), width=10, height=3, command=lambda: on_click('4'))
btn_shelf1.grid(row=0, column=0, padx=10, pady=10)
btn_shelf2.grid(row=0, column=1, padx=10, pady=10)
btn_shelf3.grid(row=1, column=0, padx=10, pady=10)
btn_shelf4.grid(row=1, column=1, padx=10, pady=10)

# Add log label
log_label = tk.Label(button_frame, text='Retrieval Logs:', font=('Arial', 14), bg='#34495E', fg='white')
log_label.grid(row=0, column=2, padx=10, pady=10)

# Add log text box
log_text = tk.Text(button_frame, width=60, height=8)
log_text.grid(row=1, column=2, padx=10, pady=10)

# Add status label
status_label = tk.Label(root, text="Waiting for input...", font=('Arial', 14), bg='#34495E', fg='white')
status_label.pack(pady=10)

# Add reset button
move_to_home_position = tk.Button(root, text='Home Position', font=('Arial', 14), width=10, height=2, command=move_to_home_position, bg='#F1C40F', fg='white')
move_to_home_position.pack(pady=20)

# Add footer label
footer_label = tk.Label(root, text='© 2023 Medication Storage Inc.', font=('Arial', 10), bg='#34495E', fg='white')
footer_label.pack(side=tk.BOTTOM, pady=10)
#Run the main loop
root.mainloop()