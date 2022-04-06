#include <Arduino.h>

#include "settings.h"
#include "distance.h"
#include "wlan.h"
#include "mqtt.h"

#define LED_PIN D4

bool light = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting...");
  pinMode(A0, INPUT);
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 0);  

  setupWlan();
  setupMqtt();

  
}

void loop()
{
  analogWrite(LED_PIN, 0);
  delay(50);
  float value = analogRead(A0);

  analogWrite(LED_PIN, 100);
  sendData("light", value);
  delay(50);
}