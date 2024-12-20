#include <Arduino.h>
#include "Mediator.h"

Mediator mediator;

void setup()
{
  mediator.setup();
}

void loop()
{
  // Handle main code logic
  mediator.manageReedSensor();
}
