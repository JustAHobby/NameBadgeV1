#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
const int  buttonPin = 1;    // the pin that the pushbutton is attached to

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int currentName = 1;    // loop to call what name to display


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);  // button input
  alpha4.begin(0x70);  // pass in the address
  
  alpha4.writeDigitRaw(3, 0x0);
  alpha4.writeDigitRaw(0, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(0, 0x0);
  alpha4.writeDigitRaw(1, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(1, 0x0);
  alpha4.writeDigitRaw(2, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(2, 0x0);
  alpha4.writeDigitRaw(3, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  
  alpha4.clear();
  alpha4.writeDisplay();
  writeName();
}

void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // display the next name and iterate/loop the name;
      currentName = currentName + 1;
      if(currentName > 3) { //we have 3 names so if we hit 4 loop back
        currentName = 1;
      }
      nextName();
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
}

void nextName() {
  if(currentName == 1) {
    writeName();
  } else if(currentName == 2) {
    writeDept();
  } else if(currentName == 3) {
    writeAltName();
  }
}

void writeName() {
  // pre clear display
  alpha4.clear();
  alpha4.writeDisplay();
  
  // setup characters for name
  alpha4.writeDigitAscii(0, 'M');
  alpha4.writeDigitAscii(1, 'A');
  alpha4.writeDigitAscii(2, 'T');
  alpha4.writeDigitAscii(3, 'T');
  
  // write it out
  alpha4.writeDisplay();
  delay(200);
}

void writeDept() {
  // pre clear display
  alpha4.clear();
  alpha4.writeDisplay();
  
  // setup characters for name
  alpha4.writeDigitAscii(0, 'D');
  alpha4.writeDigitAscii(1, 'T');
  alpha4.writeDigitAscii(2, 'C');
  alpha4.writeDigitAscii(3, 'I');
  
  // write it out
  alpha4.writeDisplay();
  delay(200);
}

void writeAltName() {
  // pre clear display
  alpha4.clear();
  alpha4.writeDisplay();
  
  // setup characters for name
  alpha4.writeDigitAscii(0, 'Z');
  alpha4.writeDigitAscii(1, 'U');
  alpha4.writeDigitAscii(2, 'R');
  alpha4.writeDigitAscii(3, 'G');
  
  // write it out
  alpha4.writeDisplay();
  delay(200);
}
