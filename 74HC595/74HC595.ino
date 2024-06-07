/*
  Physical Pixel

  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.

  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.

  The circuit:
  - LED connected from digital pin 13 to ground through 220 ohm resistor

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/PhysicalPixel
*/

int binaryData ;      // a variable to read incoming serial data into

const int dataPin = 11;   // DS (Serial Data Input)
const int latchPin = 8;   // ST_CP (Latch Pin)
const int clockPin = 10;  // SH_CP (Clock Pin)

void setup() {

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {

    int incomingInt = Serial.parseInt();

    // Ensure the integer is within 0-255 range
    byte binaryData = incomingInt & 0xFF;

    // Send data to the 74HC595
    shiftOut(dataPin, clockPin, MSBFIRST, binaryData);

    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
  }
}