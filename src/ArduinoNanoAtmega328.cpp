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

void Microcontroller::manageSensor()
{
    // Read input from sensor
    int current_sensor_input = digitalRead(PIN_D2);
    if (current_sensor_input == LOW && previous_sensor_input == HIGH)
    {
        Serial.println("Door has been opened!");
        digitalWrite(PIN_D3, LOW);
    }

    previous_sensor_input = current_sensor_input;

    Serial.print("CURRENT SENSOR INPUT: ");
    Serial.println(current_sensor_input);

    Serial.print("PREVIOUS SENSOR INPUT: ");
    Serial.println(previous_sensor_input);

    delay(TIMEOUT); // Delay the execution loop for 100ms
    digitalWrite(PIN_D3, HIGH);
}

uint8_t Microcontroller::getRingLedPin()
{
    return PIN_D4;
}

void Microcontroller::delayMicroController(unsigned long ms)
{
    delay(ms);
}