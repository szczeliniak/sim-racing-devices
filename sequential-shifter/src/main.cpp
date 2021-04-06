#include <Arduino.h>

#include "SequentialShifter.h"

#define SEQUENTIAL_SHIFTER_REPORT_ID 0x04
#define SEQUENTIAL_SHIFTER_UP 4
#define SEQUENTIAL_SHIFTER_DOWN 2

#define DELAY 10

SequentialShifter *shifter;

void setup() {

  shifter = new SequentialShifter(SEQUENTIAL_SHIFTER_REPORT_ID, SEQUENTIAL_SHIFTER_UP, SEQUENTIAL_SHIFTER_DOWN);
  shifter->setup();

}

void loop() {

  shifter->loop();
  delay(DELAY);
  
}