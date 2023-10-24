Arduino CAN Communication with MCP2515
This project demonstrates Arduino code for establishing bidirectional CAN (Controller Area Network) communication between two Arduino boards using the MCP2515 CAN controller module. One Arduino serves as the transmitter, while the other acts as the receiver.

Features
Transmitter Arduino
Reads data from a button or another source.
Sends data over the CAN bus using the MCP2515 module.
Controls a servo motor based on the received data.
Receiver Arduino
Receives data sent by the transmitter via the CAN bus.
Controls an LED and a servo motor based on the received data.
Monitors a potentiometer to send data back to the transmitter.
Hardware Components
To replicate this project, you will need the following hardware components:

Arduino boards
MCP2515 CAN controller modules
Servo motors
LED
Potentiometer
Usage
Upload the provided code to your Arduino boards.
Connect the necessary hardware components as described in the code and comments.
Observe bidirectional communication between the Arduino boards, allowing you to control servo motors, LEDs, and potentiometers based on the exchanged data.
