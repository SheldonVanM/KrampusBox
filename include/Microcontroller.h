#include <stdio.h>
#ifndef __Microcontroller_H_INCLUDED
#define __Microcontroller_H_INCLUDED

/* A strategy for the various potential microcontrollers we may employ */
class Microcontroller
{
private:
    // declare variables
    int current_sensor_input;
    int previous_sensor_input;

public:
    void setupMicrocontroller();

    uint8_t getRingLedPin();

    int getSensorInput();

    void writePin(bool activate, int pin);

    void delayMicroController(unsigned long ms);

    int getSoundOne();

    int getSoundTwo();

    int getSoundThree();

    int getSoundFour();

    int getSoundFive();

    int getSoundSix();

    int getSoundSeven();
};

#endif