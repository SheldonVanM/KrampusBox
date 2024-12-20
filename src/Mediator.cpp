#include "Mediator.h"

void Mediator::setup()
{
    microcontroller.setupMicrocontroller();
    ring.startup();
    ring.changeBrightness(this->LED_BRIGHTNESS);
    this->triggerPreviouslyEngaged = false;
}

/* Checks to see if door has been opened */
bool Mediator::isTriggerActivated()
{
    return this->current_sensor_input == LOW && this->previous_sensor_input == HIGH;
}

/* Checks to see if door has been closed (only after being previously opened) */
bool Mediator::isTriggerDisengaged()
{
    return this->current_sensor_input == HIGH && this->previous_sensor_input == LOW && this->triggerPreviouslyEngaged;
}

void Mediator::manageReedSensor()
{
    // microcontroller.activateSound(false, 0);
    audiocontroller.turnOffSound();
    this->current_sensor_input = microcontroller.getSensorInput();
    // Turn lights ON when the lid is open
    if (this->isTriggerActivated())
    {
        // microcontroller.activateSound(true, 0);
        audiocontroller.playRandomSound();
        manageLighting(true);
        this->triggerPreviouslyEngaged = true;
    }
    microcontroller.delayMicroController(300);
    // Turn lights OFF when the lid is closed
    if (this->isTriggerDisengaged())
    {
        manageLighting(false);
        this->triggerPreviouslyEngaged = false;
    }
    this->previous_sensor_input = this->current_sensor_input;
}

void Mediator::manageLighting(bool turnOn)
{
    if (turnOn)
    {
        ring.turnRingOn(255, 0, 0);
    }
    else
    {
        ring.clear();
    }
}