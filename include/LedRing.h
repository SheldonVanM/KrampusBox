#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <stdio.h>
#include "Microcontroller.h"

class LedRing
{
private:
    Microcontroller microcontroller;
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(48, microcontroller.getRingLedPin(), NEO_GRB + NEO_KHZ800);
    uint16_t previousNumOfIlluminatedPixels = 0;

public:
    void startup();

    void changeBrightness(uint8_t brightness);

    void changeColor(uint32_t color);

    void changeColor(uint8_t red, uint8_t green, uint8_t blue);

    void turnRingOn(uint32_t color);

    void turnRingOn(uint8_t red, uint8_t green, uint8_t blue);

    void clear();
};