#include <Servo.h>
#include <SPI.h>
#include <mcp2515.h>
struct can_frame canMsg1;
struct can_frame canMsg2;
MCP2515 mcp2515(10);    // Create an MCP2515 object, specifying CS pin 10

const int servoPin = 9; // Pin where the servo motor is connected
#define buttonPin 5   // Pin where the button is connected

Servo myservo; // Create servo object to control a servo

void setup() {
   canMsg1.can_id  = 0x000;   // Set the CAN message ID for message 1
   canMsg1.can_dlc = 1;       // Set the data length for message 1
   canMsg2.can_id  = 0x000;   // Set the CAN message ID for message 2
   canMsg2.can_dlc = 1;       // Set the data length for message 2
   myservo.attach(servoPin); // Attach the servo on pin 9 to the servo object
    
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for the button
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();

}


void loop() {
  if (mcp2515.readMessage(&canMsg1) == MCP2515::ERROR_OK) {
    int val = canMsg1.data[0]; // Read an integer from the received CAN message
    myservo.write(val); // Set the servo position
    delay(100);
  }

  if (digitalRead(buttonPin) == LOW) { // Check the state of the button
    delay(50); // Debounce the button
    if (digitalRead(buttonPin) == LOW) {
      canMsg2.data[0]=1;    // Set the data for message 2 to 1
      mcp2515.sendMessage(&canMsg2); // Send a signal to the second Arduino
    }
  }
}
