#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{

public:
    virtual ~Controller() {}
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif