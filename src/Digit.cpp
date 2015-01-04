
#include "Digit.h"
#include "Arduino.h"

Digit::Digit() { }

void Digit::init(bool value, int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _value = value;
}

void Digit::setVal(bool newValue)
{
  _value = newValue;
}

void Digit::render(void)
{
  if ( _value ) {
    on();
  } else {
    off();
  }
}

void Digit::on(void)
{
  digitalWrite(_pin, HIGH);
}

void Digit::off(void)
{
  digitalWrite(_pin, LOW);
}
