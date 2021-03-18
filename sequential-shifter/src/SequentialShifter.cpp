#include "SequentialShifter.h"

SequentialShifter::SequentialShifter(uint8_t reportId, uint8_t up, uint8_t down) : up(up), down(down)
{
    joystick = new Joystick_(reportId);
}

SequentialShifter::~SequentialShifter()
{
    delete joystick;
}

void SequentialShifter::setup()
{
    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);

    joystick->begin();
};

void SequentialShifter::loop()
{

    upValue = digitalRead(up);
    downValue = digitalRead(down);

    joystick->setButton(0, !upValue);
    joystick->setButton(1, !downValue);
};