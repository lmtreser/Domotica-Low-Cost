/*
  * Dispositivo Domotico
  * Ejemplo de aplicación con la placa ESP32
  *
  * Utiliza las bibliotecas:
  *
  *   "PubSubClient" de Nick O’Leary
  *   https://github.com/knolleary/pubsubclient
  *
  *   "DHT_sensor_library" de Adafruit
  *   https://github.com/adafruit/DHT-sensor-library
  * 
  * created  18 Sep 2024
  * modified 29 May 2025
  * by Lucas Martin Treser
  * 
*/

#include "DHT.h"
#include "mqtt_conn.h"

//=====[#Defines]=====================================//
#define DELAY_TIME 5000
#define RELE_PIN 13
#define DHTPIN 4
#define DHTTYPE DHT11
//=====[Credenciales WiFi]============================//
const char* wifi_ssid =     "Movistar-B3F360";
const char* wifi_password = "PKCU9JM3EE";
//=====[Credenciales MQTT]============================//
const char* mqtt_server =   "192.168.1.40";
const int mqtt_port =       1883;
//=====[Topics MQTT]==================================//
const char* mqtt_topic_1 = "home/living/sensor_int";
const char* mqtt_topic_2 = "home/living/sensor_float";
const char* mqtt_topic_3 = "home/garage/sensor_bool";
const char* mqtt_topic_4 = "home/garage/sensor_char";
//=====[Objetos globales]============================//
DHT dht(DHTPIN, DHTTYPE);
//===================================================//

void setup() {
  
  smartHomeInit();  // Inicializa pines y Serial
  smartHomeWifiInit(wifi_ssid, wifi_password);
  smartHomeMqttInit(mqtt_server, mqtt_port);
  smartHomeMqttSubscribe(mqtt_topic_3);

  pinMode(RELE_PIN, OUTPUT);
  digitalWrite(RELE_PIN, HIGH);
  dht.begin();
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

      if (message == "true") {
        Serial.println("Encendiendo luz...");
        digitalWrite(RELE_PIN, LOW);
      } else if (message == "false") {
        Serial.println("Apagando luz...");
        digitalWrite(RELE_PIN, HIGH);
      }

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
    // int temperatura = random(0, 40);
    // float humedad = random(50, 90) + 0.5;
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity();
    const char* string = "ESP32 MQTT Live!";

    // Publicar mediante MQTT
    smartHomeMqttPublish(mqtt_topic_1, temperatura);
    smartHomeMqttPublish(mqtt_topic_2, humedad);
    smartHomeMqttPublish(mqtt_topic_4, string);
  }
}
