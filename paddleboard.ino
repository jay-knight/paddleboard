#include "DigiKeyboard.h"
// https://github.com/digistump/DigistumpArduino/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboard.h

// define input pins that the paddles are attached to
// Pin1 on the digispark always reads low without an external pull-up resistor
const int ditPin = 0;
const int dahPin = 2;

int last = 0;

void setup() {
  pinMode(ditPin, INPUT_PULLUP);
  pinMode(dahPin, INPUT_PULLUP);
  DigiKeyboard.sendKeyStroke(0);
}

void loop() {

  DigiKeyboard.update();

  // Get current state of paddles
  int ditOn = digitalRead(ditPin) == LOW;
  int dahOn = digitalRead(dahPin) == LOW;

  // The modifier keys use a bit array (byte) to represent which ones are pressed.
  // Left Control is 1 (00000001)
  // Right Control is 16 (00001000) 
  int modifiers = 0;
  if (ditOn) {
    modifiers += MOD_CONTROL_LEFT;
  }
  if (dahOn) {
    modifiers += MOD_CONTROL_RIGHT;
  }

  // only update what is being sent if the state has changed
  if (modifiers != last) {
    DigiKeyboard.sendKeyPress(0, modifiers);
  }
  
  last = modifiers;
}
