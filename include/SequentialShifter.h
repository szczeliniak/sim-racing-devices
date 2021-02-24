#ifndef SEQUENTIAL_SHITER_H
#define SEQUENTIAL_SHITER_H

#include <Joystick.h>
#include "Controller.h"

class SequentialShifter : public Controller
{

private:
    Joystick_ Joystick;
    uint8_t up;
    uint8_t down;
    int upValue = 0;
    int downValue = 0;

public:
    SequentialShifter(uint8_t up, uint8_t down);
    void setup();
    void loop();
};

#endif