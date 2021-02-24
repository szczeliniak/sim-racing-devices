#include <Arduino.h>
#include "logitech-shifter/LogitechShifter.h"

LogitechShifter logitechShifter(A0, A2, 2);

void setup()
{
  logitechShifter.setup();
}

void loop()
{
  logitechShifter.loop();

  delay(50);
}