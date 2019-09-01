#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
const int  buttonPin = 1;    // the pin that the pushbutton is attached to

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

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
  Serial.println("ready");
}

void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // clean display to show button was pressed
      alpha4.clear();
      alpha4.writeDisplay();
    } else {
      writeName();
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
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
