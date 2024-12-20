#include "Microcontroller.h"
#include <Arduino.h>

// Definitions
#define PIN_D2 (2)
#define PIN_D3 (3)
#define PIN_D4 (4)
#define TIMEOUT (300)

void Microcontroller::setupMicrocontroller()
{
    // Setup
    Serial.begin(9600); // Using baud rate of 9600

    // Setup the pinmodes
    pinMode(PIN_D2, INPUT);
    pinMode(PIN_D3, OUTPUT);
    // preprocess
    previous_sensor_input = HIGH;
    digitalWrite(PIN_D3, HIGH);
}

int Microcontroller::getSensorInput()
{
    return digitalRead(PIN_D2);
}

void Microcontroller::activateSound(bool activate)
{
    if (activate)
    {
        digitalWrite(PIN_D3, LOW);
    }
    else
    {
        digitalWrite(PIN_D3, HIGH);
    }
}

uint8_t Microcontroller::getRingLedPin()
{
    return PIN_D4;
}

void Microcontroller::delayMicroController(unsigned long ms)
{
    delay(ms);
}