#ifndef __Mediator_H_INCLUDED
#define __Mediator_H_INCLUDED

#include "LedRing.h"
#include "Microcontroller.h"

class Mediator
{
protected:
    Microcontroller microcontroller;
    LedRing ring;
    int previous_sensor_input;
    int current_sensor_input;

public:
    /**/
    void setup();

    /**/
    void manageReedSensor();

    /**/
    bool isTriggerActivated();

    /**/
    void manageLighting();
};

#endif