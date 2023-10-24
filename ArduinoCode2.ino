#include <SPI.h>
#include <mcp2515.h>
struct can_frame canMsg1;
struct can_frame canMsg2;
MCP2515 mcp2515(10);    // Create an MCP2515 object, specifying CS pin 10

#define ledPin 12   // Pin where the LED is connected
const int pot = A0;  // Pin where the pot is connected

void setup() {
   canMsg1.can_id  = 0x000;   // Set the CAN message ID for message 1
   canMsg1.can_dlc = 1;       // Set the data length for message 1
   canMsg2.can_id  = 0x000;   // Set the CAN message ID for message 2
   canMsg2.can_dlc = 1;       // Set the data length for message 2
  pinMode(ledPin, OUTPUT);
  pinMode(pot, INPUT);
  digitalWrite(ledPin,LOW);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
}

void loop() {
   if (mcp2515.readMessage(&canMsg2) == MCP2515::ERROR_OK) {
    int receivedValue = canMsg2.data[0];
    if (receivedValue == 1) {
         digitalWrite(ledPin, !digitalRead(ledPin));
    }
  }
  int potValue = analogRead(pot);
  int mappedValue = map(potValue, 0, 1023, 0, 180); // Map potentiometer value to servo angle range (0-180)
//>>2,/4
  // Send potentiometer value via UART to slave
   canMsg1.data[0]=mappedValue;
   mcp2515.sendMessage(&canMsg1); // Send a signal to the second Arduino
  delay(100);
  
 
}
