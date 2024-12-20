#include "Microcontroller.h"
#include <Arduino.h>

// DEFINITIONS
// For Sensors
#define PIN_D2 (2)
// For sounds
#define PIN_D3 (3)
#define PIN_D4 (4)
#define PIN_D5 (5)
#define PIN_D6 (6)
#define PIN_D7 (7)
#define PIN_D8 (8)
#define PIN_D9 (9)
// For visuals
#define PIN_D12 (12)
// Auxillary
#define TIMEOUT (300)

void Microcontroller::setupMicrocontroller()
{
    // Setup
    Serial.begin(9600); // Using baud rate of 9600

    // Setup the pinmodes
    pinMode(PIN_D2, INPUT);

    pinMode(PIN_D3, OUTPUT);
    pinMode(PIN_D4, OUTPUT);
    pinMode(PIN_D5, OUTPUT);
    pinMode(PIN_D6, OUTPUT);
    pinMode(PIN_D7, OUTPUT);
    pinMode(PIN_D8, OUTPUT);
    pinMode(PIN_D9, OUTPUT);
    // preprocess
    previous_sensor_input = HIGH;
    digitalWrite(PIN_D3, HIGH);
    digitalWrite(PIN_D4, HIGH);
    digitalWrite(PIN_D5, HIGH);
    digitalWrite(PIN_D6, HIGH);
    digitalWrite(PIN_D7, HIGH);
    digitalWrite(PIN_D8, HIGH);
    digitalWrite(PIN_D9, HIGH);
}

int Microcontroller::getSensorInput()
{
    return digitalRead(PIN_D2);
}

void Microcontroller::writePin(bool activate, int pin)
{
    if (activate)
    {
        digitalWrite(pin, LOW);
    }
    else
    {
        digitalWrite(pin, HIGH);
    }
}

uint8_t Microcontroller::getRingLedPin()
{
    return PIN_D12;
}

void Microcontroller::delayMicroController(unsigned long ms)
{
    delay(ms);
}

int Microcontroller::getSoundOne()
{
    return PIN_D3;
}

int Microcontroller::getSoundTwo()
{
    return PIN_D4;
}

int Microcontroller::getSoundThree()
{
    return PIN_D5;
}

int Microcontroller::getSoundFour()
{
    return PIN_D6;
}

int Microcontroller::getSoundFive()
{
    return PIN_D7;
}

int Microcontroller::getSoundSix()
{
    return PIN_D8;
}

int Microcontroller::getSoundSeven()
{
    return PIN_D9;
}
