# Arduino_CAN_MCP2515.

Description:

This repository contains Arduino code for implementing CAN (Controller Area Network) communication between two Arduino boards using the MCP2515 CAN controller module. The project demonstrates bidirectional communication with two Arduino boards where one board serves as the transmitter, and the other as the receiver.

Features:

Transmitter Arduino:

Reads data from a button or other sources.
Sends the data over the CAN bus using the MCP2515 module.
Controls a servo motor based on the received data.
Receiver Arduino:

Receives data sent by the transmitter via the CAN bus.
Controls an LED and a servo motor based on the received data.
Monitors a potentiometer to send data back to the transmitter.
Key Components:

Arduino boards
MCP2515 CAN controller modules
Servo motors
LED
Potentiometer
