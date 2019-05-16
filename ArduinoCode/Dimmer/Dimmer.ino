/*
  Dimmer

  Demonstrates sending data from the computer to the Arduino board, in this case
  to control the brightness of an LED. The data is sent in individual bytes,
  each of which ranges from 0 to 255. Arduino reads these bytes and uses them to
  set the brightness of the LED.

  The circuit:
  - LED attached from digital pin 13 to ground (LED_BUILTIN)
  - Serial connection to Processing, Max/MSP, or another serial application

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Dimmer
*/

//const int ledPin = 9;      // the pin that the LED is attached to
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the LED_BUILTIN as an output:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  byte brightness;
  // check if data has been sent from the computer:
  if (Serial.available()>0) {
    // read the most recent 1 byte (which will be from 0 to 255):
    brightness = Serial.read();
    // set brightness of LED
    analogWrite(LED_BUILTIN,brightness);
    // write brightness to serial port
    Serial.write(brightness); 
  }
}
