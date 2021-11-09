#include <Arduino.h>

#include "settings.h"
#include "distance.h"
#include "wlan.h"
#include "mqtt.h"

#define LED_PIN D4

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 0);

  setupDistanceCalculation();
  setupWlan();
  setupMqtt();

  analogWrite(LED_PIN, 255);
}

void loop()
{
  float distance = calculateDistance();

  if (distance > 300)
    return;

  sendDistanceData(distance);

  delay(1000);
}