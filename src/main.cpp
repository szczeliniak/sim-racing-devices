#include <Arduino.h>
#include "LogitechShifter.h"
#include "SequentialShifter.h"
#include "Handbrake.h"

#define LOGITECH_SHIFTER_AXIS_X A0
#define LOGITECH_SHIFTER_AXIS_Y A2
#define LOGITECH_SHIFTER_REVERSE_BUTTON 2
#define SEQUENTIAL_SHIFTER_UP 8
#define SEQUENTIAL_SHIFTER_DOWN 5
#define HANDBRAKE_PIN 4
#define DELAY 20

LogitechShifter logitechShifter(LOGITECH_SHIFTER_AXIS_X, LOGITECH_SHIFTER_AXIS_Y, LOGITECH_SHIFTER_REVERSE_BUTTON);
SequentialShifter sequentialShifter(SEQUENTIAL_SHIFTER_UP, SEQUENTIAL_SHIFTER_DOWN);
Handbrake handbrake(HANDBRAKE_PIN);

void setup()
{
  logitechShifter.setup();
  sequentialShifter.setup();
  handbrake.setup();
}

void loop()
{
  logitechShifter.loop();
  sequentialShifter.loop();
  handbrake.loop();
  delay(DELAY);
}