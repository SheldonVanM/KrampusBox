#include <Arduino.h>
#include "Microcontroller.h"

Microcontroller microcontroller;

void setup()
{
  microcontroller.setupMicrocontroller();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

int getRingLedPin()
{
  return PIN_D4;
}