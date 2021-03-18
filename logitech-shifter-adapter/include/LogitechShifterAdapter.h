#ifndef LOGITECH_SHITER_H
#define LOGITECH_SHITER_H

#include <Joystick.h>

// H-shifter mode analog axis thresholds
#define HS_XAXIS_12 400
#define HS_XAXIS_56 600
#define HS_YAXIS_135 800
#define HS_YAXIS_246 300

// Digital inputs definitions
#define DI_REVERSE 1
#define DI_MODE 3

class LogitechShifterAdapter
{

private:
    Joystick_ *joystick;
    uint8_t axisX;
    uint8_t axisY;
    uint8_t reverseButton;
    int b[16];
    int gear = 0;            // Default value is neutral
    int lastButtonState = 0; // Last state of the button

    void desactivar();

public:
    LogitechShifterAdapter(uint8_t reportId, uint8_t axisX, uint8_t axisY, uint8_t reverseButton);
    ~LogitechShifterAdapter();
    void setup();
    void loop();
};

#endif