#include "LogitechShifterAdapter.h"

LogitechShifterAdapter::LogitechShifterAdapter(uint8_t reportId, uint8_t axisX, uint8_t axisY, uint8_t reverseButton) : axisX(axisX), axisY(axisY), reverseButton(reverseButton)
{
    joystick = new Joystick_(reportId, JOYSTICK_TYPE_GAMEPAD, 8, 0, false, false, false, false, false, false, false, false, false, false, false);
}

LogitechShifterAdapter::~LogitechShifterAdapter()
{
    delete joystick;
}

void LogitechShifterAdapter::setup()
{
    pinMode(axisX, INPUT_PULLUP); // X axis
    pinMode(axisY, INPUT_PULLUP); // Y axis

    pinMode(reverseButton, INPUT);

    for (int i = 0; i < 16; i++)
    {
        b[i] = 0;
    }

    b[DI_MODE] = 0;
    joystick->begin();
}

void LogitechShifterAdapter::loop()
{
    int x = analogRead(axisX); // X axis
    int y = analogRead(axisY); // Y axis

    Serial.println(x);
    Serial.println(y);

    int _isreverse = digitalRead(reverseButton);
    int _gear_ = 0;

    if (_isreverse == 1)
    {
        _gear_ = 8;
        b[DI_REVERSE] = 1;
    }
    else
    {

        if (b[DI_MODE] == 0) // H-shifter mode?
        {
            if (x < HS_XAXIS_12) // Shifter on the left?
            {
                if (y > HS_YAXIS_135)
                    _gear_ = 1; // 1st gear
                if (y < HS_YAXIS_246)
                    _gear_ = 2; // 2nd gear
            }
            else if (x > HS_XAXIS_56) // Shifter on the right?
            {
                if (y > HS_YAXIS_135)
                    _gear_ = 5; // 5th gear
                if (y < HS_YAXIS_246)
                    _gear_ = 6; // 6th gear
            }
            else // Shifter is in the middle
            {
                if (y > HS_YAXIS_135)
                    _gear_ = 3; // 3rd gear
                if (y < HS_YAXIS_246)
                    _gear_ = 4; // 4th gear
            }
        }
    }

    if (gear != 6)
        b[DI_REVERSE] = 0; // Reverse gear is allowed only on 6th gear position

    if (_gear_ != gear)
    {
        Serial.print(x);
        gear = _gear_;
        desactivar();
        joystick->setButton(gear - 1, HIGH);
    }
}

void LogitechShifterAdapter::desactivar()
{
    for (int i = 0; i <= 10; i++)
    {
        joystick->setButton(i, LOW);
    }
}
