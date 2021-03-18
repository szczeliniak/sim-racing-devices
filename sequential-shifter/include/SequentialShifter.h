#ifndef SEQUENTIAL_SHITER_H
#define SEQUENTIAL_SHITER_H

#include <Joystick.h>

class SequentialShifter
{

private:
    Joystick_ *joystick;
    uint8_t up;
    uint8_t down;
    int upValue = 0;
    int downValue = 0;

public:
    SequentialShifter(uint8_t reportId, uint8_t up, uint8_t down);
    ~SequentialShifter();
    void setup();
    void loop();
};

#endif