import tkinter as tk
import serial

# Constants
#COM_PORT = 'COM3'
#BAUD_RATE = 9600

# Create a serial connection to Arduino
#ser = serial.Serial(COM_PORT, BAUD_RATE)

# Define the function to send the selected shelf to Arduino
def send_shelf(shelf):
    ser.write(shelf.encode())
    status_label.config(text=f"Retrieving medication from Shelf {shelf}...")  # update the status label

# Define the function to handle the button click event
def on_click(shelf):
    send_shelf(shelf)
    # Add code to control the robot arm to pick up the item from the selected shelf and place it on the counter
    # For example:
    # ser.write('P'.encode())  # send command to Arduino to activate the robot arm's picking action
    # ser.write('D'.encode())  # send command to Arduino to activate the robot arm's delivery action

# Define the function to reset the robot arm to its initial position
def reset_robot():
    ser.write('R'.encode())
    status_label.config(text="Robot arm reset to initial position")  # update the status label

# Create a window and add buttons for each shelf
root = tk.Tk()
root.geometry('500x350')
root.title('Medication Storage Control System')

# Set background color
root.configure(bg='#F7F7F7')

# Add title label
title_label = tk.Label(root, text='Medication Storage', font=('Arial', 20, 'bold'), bg='#F7F7F7')
title_label.pack(pady=20)

# Add subtitle label
subtitle_label = tk.Label(root, text='Select the shelf to retrieve medication:', font=('Arial', 14), bg='#F7F7F7')
subtitle_label.pack(pady=10)

# Add buttons for each shelf
button_frame = tk.Frame(root, bg='#F7F7F7')
button_frame.pack(pady=10)

btn_shelf1 = tk.Button(button_frame, text='Shelf 1', font=('Arial', 14), width=10, height=3, command=lambda: on_click('1'))
btn_shelf2 = tk.Button(button_frame, text='Shelf 2', font=('Arial', 14), width=10, height=3, command=lambda: on_click('2'))
btn_shelf3 = tk.Button(button_frame, text='Shelf 3', font=('Arial', 14), width=10, height=3, command=lambda: on_click('3'))
btn_shelf4 = tk.Button(button_frame, text='Shelf 4', font=('Arial', 14), width=10, height=3, command=lambda: on_click('4'))

btn_shelf1.grid(row=0, column=0, padx=10, pady=10)
btn_shelf2.grid(row=0, column=1, padx=10, pady=10)
btn_shelf3.grid(row=1, column=0, padx=10, pady=10)
btn_shelf4.grid(row=1, column=1, padx=10, pady=10)

# Add status label
status_label = tk.Label(root, text='Ready', font=('Arial', 14), fg='#BFBFBF', bg='#F7F7F7')
status_label.pack(pady=20)

# Add reset button
reset_button = tk.Button(root, text='Reset Robot Arm', font=('Arial', 14), bg='#E6E6E6', command=reset_robot)
reset_button.pack(pady=10)

# Start the GUI

# Start the GUI
root.mainloop()
