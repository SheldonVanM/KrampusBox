#include "Mediator.h"

void Mediator::setup()
{
    microcontroller.setupMicrocontroller();
}

bool Mediator::isTriggerActivated()
{
    return this->current_sensor_input == LOW && this->previous_sensor_input == HIGH;
}

void Mediator::manageReedSensor()
{
    microcontroller.activateSound(false);
    this->current_sensor_input = microcontroller.getSensorInput();
    if (this->isTriggerActivated())
    {
        microcontroller.activateSound(true);
        manageLighting();
    }
    microcontroller.delayMicroController(300);
    this->previous_sensor_input = this->current_sensor_input;
}

void Mediator::manageLighting()
{
}