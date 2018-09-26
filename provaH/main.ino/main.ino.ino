/*
  Project: Bluetooth AT-09 BLE module ZS-40 AT comms using software serial library
  Function: Uses hardware serial to talk to the host computer and software serial
          for communication with the Bluetooth module. Intended for Bluetooth
          devices that require line end characters "\r\n". When a command is entered
          in the serial monitor on the computer the Arduino will relay it to the
          bluetooth module and display the result.
  Pins
  Arduino  - Bluetooth AT-09 BLE module ZS-40
  5V pin     VCC pin
  GND pin    GND pin
  Digital 3  RX pin through a voltage divider
  Digital 2  TX pin (no need voltage divider)

*/
//*********************************************************************************
#include <SoftwareSerial.h>//include library code
//*********************************************************************************
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the AT-09 BLE TX to the Arduino RX on pin 2. 
// Connect the AT-09 BLE RX to the Arduino TX on pin 3 through a voltage divider.
//*********************************************************************************
void setup()
{
  Serial.begin(9600);//initialize serial communication at 9600 bps
  BTserial.begin(9600);  //It can also be configured to have different baud rates:9600,
//19200,38400 etc. By default the baud rate is 9600. If 9600 doesn't work try different baud rate
}
void loop()
{
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BTserial.available())
  {   
    Serial.write(BTserial.read());
  }
  // Read from the Arduino Serial Monitor and send to the Bluetooth module
  if (Serial.available())
  {    
    BTserial.write(Serial.read());    
    }
  }

