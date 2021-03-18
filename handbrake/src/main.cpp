#include <Arduino.h>
#include "Handbrake.h"

#define HANDBRAKE_REPORT_ID 0x05
#define HANDBRAKE_PIN A2

#define DELAY 10

Handbrake *handbrake;

void setup() {

  handbrake = new Handbrake(HANDBRAKE_REPORT_ID, HANDBRAKE_PIN);
  handbrake->setup();

}

void loop() {
  
  handbrake->loop();
  delay(DELAY);

}