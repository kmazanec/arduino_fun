/*
 * Digit - Used for storing and toggling a single digit
 * useful for managing arrays of leds
 * Created by Keith Mazanec Jan 2, 2015
*/

#ifndef Digit_h
#define Digit_h

class Digit
{
  public:
    Digit();
    void init(bool value, int pin);
    void render(void);
    void setVal(bool newValue);
  private:
    void on(void);
    void off(void);
    bool _value;
    int _pin;
};


#endif
