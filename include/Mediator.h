#ifndef __Mediator_H_INCLUDED
#define __Mediator_H_INCLUDED

#include "LedRing.h"
#include "Microcontroller.h"
#include "Audiocontroller.h"

class Mediator
{
protected:
    Microcontroller microcontroller;
    LedRing ring;
    Audiocontroller audiocontroller;
    int previous_sensor_input;
    int current_sensor_input;
    uint8_t LED_BRIGHTNESS = 200;
    bool triggerPreviouslyEngaged;

public:
    /**/
    void setup();

    /**/
    void manageReedSensor();

    /**/
    bool isTriggerActivated();

    /**/
    bool isTriggerDisengaged();

    /**/
    void manageLighting(bool turnOn);
};

#endif