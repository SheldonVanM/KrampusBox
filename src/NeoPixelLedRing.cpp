#include "LedRing.h"

/**/
void LedRing::startup()
{
    strip.begin();
    strip.clear(); // Initialize the pixels to off
    //  Start on setup begin by showing a chase sequence for LED ring
    clear();
}

/* */
void LedRing::changeBrightness(uint8_t brightness)
{
    this->strip.setBrightness(brightness);
}

void LedRing::changeColor(uint32_t color)
{
    for (uint16_t i = 0; i < this->strip.numPixels(); i++)
    {
        this->strip.setPixelColor(i, color);
    }
    this->strip.show();
}

void LedRing::changeColor(uint8_t red, uint8_t green, uint8_t blue)
{
    this->changeColor(this->strip.Color(red, green, blue));
}