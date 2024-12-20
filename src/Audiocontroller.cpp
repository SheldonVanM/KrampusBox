#include "Audiocontroller.h"

void Audiocontroller::playSound(int pin)
{
    this->pin = pin;
    microcontroller.writePin(true, pin);
}

void Audiocontroller::turnOffSound()
{
    microcontroller.writePin(false, this->pin);
}

void Audiocontroller::playRandomSound()
{
    // int MIN_INDEX = 0;
    // int MAX_INDEX = sizeof(audio_pins) / sizeof(audio_pins[0]) - 1;
    // int i = (rand() / RAND_MAX) * (MAX_INDEX - MIN_INDEX);
    int LENGTH = sizeof(audio_pins) / sizeof(audio_pins[0]);
    int index = rand() % LENGTH;
    this->pin = audio_pins[index];
    this->playSound(this->pin);
}
