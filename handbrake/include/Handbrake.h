#ifndef HANDBRAKE_SHITER_H
#define HANDBRAKE_SHITER_H

#include <Joystick.h>

class Handbrake
{

private:
    Joystick_ *joystick;
    uint8_t pin;

public:
    Handbrake(uint8_t reportId, uint8_t pin);
    ~Handbrake();
    void setup();
    void loop();
};

#endif