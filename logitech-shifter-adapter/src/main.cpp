#include <Arduino.h>
#include "LogitechShifterAdapter.h"

#define LOGITECH_SHIFTER_REPORT_ID 0x03
#define LOGITECH_SHIFTER_AXIS_X A0
#define LOGITECH_SHIFTER_AXIS_Y A2
#define LOGITECH_SHIFTER_REVERSE_BUTTON 2

#define DELAY 10

LogitechShifterAdapter *logitechShifterAdapter;

void setup() {

  logitechShifterAdapter = new LogitechShifterAdapter(LOGITECH_SHIFTER_REPORT_ID, LOGITECH_SHIFTER_AXIS_X, LOGITECH_SHIFTER_AXIS_Y, LOGITECH_SHIFTER_REVERSE_BUTTON);
  logitechShifterAdapter->setup();
  
}

void loop() {

  logitechShifterAdapter->loop();
  delay(DELAY);

}