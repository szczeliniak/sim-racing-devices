#ifndef HANDBRAKE_SHITER_H
#define HANDBRAKE_SHITER_H

#include <Joystick.h>
#include "Controller.h"

class Handbrake : public Controller
{

private:
    Joystick_ Joystick;
    uint8_t pin;

public:
    Handbrake(uint8_t pin);
    void setup();
    void loop();
};

#endif