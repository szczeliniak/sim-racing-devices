#include <Arduino.h>
#include "logitech-shifter/LogitechShifter.h"
#include "sequential-shifter/SequentialShifter.h"

LogitechShifter logitechShifter(A0, A2, 2);
SequentialShifter sequentialShifter(8, 5);

void setup()
{
  logitechShifter.setup();
  sequentialShifter.setup();
}

void loop()
{
  logitechShifter.loop();
  sequentialShifter.loop();
  
  delay(50);
}