#include <stdio.h>
#include <stdlib.h>
#include "Microcontroller.h"
#ifndef __Audioontroller_H_INCLUDED
#define __Audiocontroller_H_INCLUDED

/* A strategy for the various potential microcontrollers we may employ */
class Audiocontroller
{
protected:
    // declare variables
    Microcontroller microcontroller;
    int pin = 0;
    int audio_pins[7] = {
        microcontroller.getSoundOne(),
        microcontroller.getSoundTwo(),
        microcontroller.getSoundThree(),
        microcontroller.getSoundFour(),
        microcontroller.getSoundFive(),
        microcontroller.getSoundSix(),
        microcontroller.getSoundSeven()};

public:
    /**/
    void playRandomSound();

    /**/
    void playSound(int pin);

    /**/
    void turnOffSound();
};

#endif