#include <Arduino.h>

#define SPEED_OF_SOUND 0.034029
#define TRIGGER_PIN D6
#define ECHP_PIN D5

void setupDistanceCalculation()
{
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHP_PIN, INPUT);
}

float calculateDistance()
{
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    float duration = pulseIn(ECHP_PIN, HIGH);
    return duration * SPEED_OF_SOUND / 2;
}