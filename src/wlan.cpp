#include <ESP8266WiFi.h>

#include <settings.h>

void setupWlan()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.println("Connecting to WiFi ");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    Serial.println("Connected to WiFi ");
}