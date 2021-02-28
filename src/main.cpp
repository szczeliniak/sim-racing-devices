#include <Arduino.h>
#include "LogitechShifter.h"
#include "SequentialShifter.h"
#include "Handbrake.h"

#define LOGITECH_SHIFTER_AXIS_X A0
#define LOGITECH_SHIFTER_AXIS_Y A2
#define LOGITECH_SHIFTER_REVERSE_BUTTON 2

#define SEQUENTIAL_SHIFTER_UP 6
#define SEQUENTIAL_SHIFTER_DOWN 5

#define HANDBRAKE_PIN A4

#define DELAY 20
#define NUMBER_OF_CONTROLLERS 3

Controller *controllers[NUMBER_OF_CONTROLLERS];

void setup()
{
  controllers[0] = new LogitechShifter(LOGITECH_SHIFTER_AXIS_X, LOGITECH_SHIFTER_AXIS_Y, LOGITECH_SHIFTER_REVERSE_BUTTON);
  controllers[1] = new SequentialShifter(SEQUENTIAL_SHIFTER_UP, SEQUENTIAL_SHIFTER_DOWN);
  controllers[2] = new Handbrake(HANDBRAKE_PIN);

  for (int i = 0; i < NUMBER_OF_CONTROLLERS; i++)
  {
    controllers[i]->setup();
  }
}

void loop()
{
  for (int i = 0; i < NUMBER_OF_CONTROLLERS; i++)
  {
    controllers[i]->loop();
  }

  delay(DELAY);
}