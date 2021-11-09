#include <ESP8266WiFi.h>
#include <../lib/pubsubclient/PubSubClient.h>
#include <../lib/ArduinoJson/ArduinoJson.h>

#include <settings.h>

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setupMqtt()
{
    client.setServer(MQTT_SERVER, MQTT_PORT);
    Serial.println("Connecting to MQTT Server");

    while (!client.connected())
    {
        Serial.print(".");
        if (client.connect(MQTT_ID))
        {
            Serial.println("Connected to MQTT");
        }
        else
        {
            Serial.println("Errorcode: ");
            Serial.print(client.state());
            delay(1000);
        }
    }
}

void sendDistanceData(float distance)
{
    DynamicJsonDocument doc(256);
    char buffer[128];
    doc["distance"] = distance;
    size_t n = serializeJson(doc, buffer);

    client.publish(MQTT_TOPIC, buffer, n);
}