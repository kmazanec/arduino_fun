
#include "Digit.h"

const int BUTTON_A = 2;
const int BUTTON_B = 3;

const int A_PINS[] = { 10, 11, 12, 13 };
const int B_PINS[] = { 6, 7, 8, 9 };
const int SUM_PINS[] = { 0, 1, 4, 5 };

const int NUM_LENGTH = 4;

int a;
int b;
int sum;

int buttonStateA;
int buttonStateB;

Digit digitsA[NUM_LENGTH];
Digit digitsB[NUM_LENGTH];
Digit digitsSum[NUM_LENGTH];

void setup() {
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);

  a = 1;
  b = 1;

  sum = a + b;

  buttonStateA = HIGH;
  buttonStateB = HIGH;

  for (int i = 0; i < NUM_LENGTH; i++ ) {
    digitsA[i].init(0, A_PINS[i]);
    digitsB[i].init(0, B_PINS[i]);
    digitsSum[i].init(0, SUM_PINS[i]);
  }

  renderLEDs(digitsA, a);
  renderLEDs(digitsB, b);
  renderLEDs(digitsSum, sum);
}

void loop() {
  buttonStateA = digitalRead(BUTTON_A);
  buttonStateB = digitalRead(BUTTON_B);

  if ( buttonStateA == LOW ) {
    a = incr(a, buttonStateA);
    sum = a + b;
    renderLEDs(digitsA, a);
    renderLEDs(digitsSum, sum);
    delay(333);
  }

  if ( buttonStateB == LOW ) {
    b = incr(b, buttonStateB);
    sum = a + b;
    renderLEDs(digitsB, b);
    renderLEDs(digitsSum, sum);
    delay(333);
  }
}

int incr(int number, int buttonState) {
  if ( buttonState == LOW ) {
    if ( number >= 16 ) {
      return 1;
    } else {
      return number + 1;
    }
  }
}

void renderLEDs(Digit digits[], int value) {
  for (int i = 0; i < NUM_LENGTH; i++ ) {
    int digit = (value >> i);
    digit = digit & B0001;
    if ( digit == 1) {
      digits[i].setVal(1);
    } else {
      digits[i].setVal(0);
    }
    digits[i].render();
  }
}
