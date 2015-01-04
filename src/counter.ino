
#include "Digit.h"

const int BUTTON_PIN = 2;

const int LED_PINS[] = { 11, 10, 9, 8 };
const int LED_PINS_LENGTH = 4;
int counter;
int buttonState;

Digit digits[LED_PINS_LENGTH];

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  counter = 1;
  buttonState = HIGH;

  for (int i = 0; i < LED_PINS_LENGTH; i++ ) {
    digits[i].init(0, LED_PINS[i]);
  }

  renderLEDs();
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if ( buttonState == LOW ) {
    incrementCounter();
    renderLEDs();
    delay(333);
  }
}

void incrementCounter() {
  if ( buttonState == LOW ) {
    if ( counter >= 16 ) {
      counter = 1;
    } else {
      counter++;
    }
  }
}

void renderLEDs() {
  for (int i = 0; i < LED_PINS_LENGTH; i++ ) {
    int digit = (counter >> i);
    digit = digit & B0001;
    if ( digit == 1) {
      digits[i].setVal(1);
    } else {
      digits[i].setVal(0);
    }
    digits[i].render();
  }
}
