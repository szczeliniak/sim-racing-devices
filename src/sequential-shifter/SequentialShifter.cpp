#include "SequentialShifter.h"

SequentialShifter::SequentialShifter(uint8_t up, uint8_t down)
{
    this->up = up;
    this->down = down;
}
void SequentialShifter::setup() {
    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);

    Joystick.begin();
};

void SequentialShifter::loop() {

    upValue = digitalRead(up);
    downValue = digitalRead(down);

    Joystick.setButton(0,!upValue);
    Joystick.setButton(1,!downValue);
};