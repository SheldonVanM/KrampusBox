#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

// Definitions
#define PIN_D2 (2)
#define PIN_D3 (3)
#define TIMEOUT (300)

// declare variables
int current_sensor_input;
int previous_sensor_input;

void setup()
{
  // Setup
  Serial.begin(9600); // Using baud rate of 9600

  // Setup the pinmodes
  pinMode(PIN_D2, INPUT);
  pinMode(PIN_D3, OUTPUT);

  // preprocess
  previous_sensor_input = LOW;
  digitalWrite(PIN_D3, HIGH);
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print("CURRENT SENSOR INPUT: ");
  Serial.println(current_sensor_input);

  Serial.print("PREVIOUS SENSOR INPUT: ");
  Serial.println(previous_sensor_input);
  // Read input from sensor
  int current_sensor_input = digitalRead(PIN_D2);
  if (current_sensor_input == HIGH && previous_sensor_input == LOW)
  {
    Serial.println("Door has been opened!");
    digitalWrite(PIN_D3, LOW);
  }

  delay(TIMEOUT); // Delay the execution loop for 100ms
  digitalWrite(PIN_D3, HIGH);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}