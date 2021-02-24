#include "Handbrake.h"

Handbrake::Handbrake(uint8_t pin)
{
    this->pin = pin;
}

void Handbrake::setup()
{
    pinMode(pin, INPUT);

    Joystick.begin();
}

void Handbrake::loop()
{
    int pot = analogRead(pin);
    int mapped = map(pot, 0, 1023, 0, 255);
    {
        Joystick.setThrottle(mapped);
    }
}