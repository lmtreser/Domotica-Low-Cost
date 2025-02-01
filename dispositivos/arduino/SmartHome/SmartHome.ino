/*
  * Dispositivo Domotico
  * Ejemplo de aplicación con la placa ESP32
  *
  * Utiliza la biblioteca "PubSubClient" de Nick O’Leary
  * disponible en https://github.com/knolleary/pubsubclient
  * 
  * created 18 Sep 2024
  * by Lucas Martin Treser
  * 
*/

#include "mqtt_conn.h"

//=====[#Defines]=====================================//
#define DELAY_TIME 5000
//=====[Credenciales WiFi]============================//
const char* wifi_ssid = "ssid";
const char* wifi_password = "password";
//=====[Credenciales MQTT]============================//
const char* mqtt_server = "localhost";
const int mqtt_port = 1883;
//=====[Topics MQTT]==================================//
const char* mqtt_topic_1 = "home/living/sensor_int";
const char* mqtt_topic_2 = "home/living/sensor_float";
const char* mqtt_topic_3 = "home/garage/sensor_bool";
const char* mqtt_topic_4 = "home/garage/sensor_char";
//===================================================//

void setup() {
  smartHomeInit();  // Inicializa pines y Serial
  smartHomeWifiInit(wifi_ssid, wifi_password);
  smartHomeMqttInit(mqtt_server, mqtt_port);
  smartHomeMqttSubscribe(mqtt_topic_3);
}

void loop() {

  smartHomeMqttLoop();

  // Recibe datos
  if (mqttMessageReceived) {

    int limit = mqttDataString.indexOf(':');
    String topic = mqttDataString.substring(0, limit);
    String message = mqttDataString.substring(limit + 1);

    Serial.print("Mensaje recibido desde [");
    Serial.print(topic);
    Serial.print("]: ");
    Serial.println(message);

    if (topic == mqtt_topic_3) {
      Serial.println(message == "true" ? "Encendiendo luz..." : "Apagando luz...");
    } else if (topic == mqtt_topic_2) {
      Serial.print("Temperatura...");
    } else {
      Serial.println("Topic no reconocido.");
    }
    mqttMessageReceived = false;
  }

  // Recupera datos y los publica
  if (smartHomeDelay(DELAY_TIME)) {

    // Lectura de datos
    int temperatura = random(0, 40);
    float humedad = random(50, 90) + 0.5;
    const char* string = "ESP32 MQTT...";

    // Publicar mediante MQTT
    smartHomeMqttPublish(mqtt_topic_1, temperatura);
    smartHomeMqttPublish(mqtt_topic_2, humedad);
    smartHomeMqttPublish(mqtt_topic_4, string);
  }
}
