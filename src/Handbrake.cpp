#include "Handbrake.h"

Handbrake::Handbrake(uint8_t pin)
{
    this->pin = pin;
    joystick = new Joystick_();
}

Handbrake::~Handbrake() {
    delete joystick;
}

void Handbrake::setup()
{
    pinMode(pin, INPUT);
    joystick->begin();
}

void Handbrake::loop()
{
    int pot = analogRead(pin);
    int mapped = map(pot, 0, 1023, 0, 255);
    {
        joystick->setThrottle(mapped);
    }
}