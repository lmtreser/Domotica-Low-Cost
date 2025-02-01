/*
 * Manejo de conectividad WiFi y MQTT
 *
 * created 18 Sep 2024
 * by Lucas Martin Treser (github: @lmtreser) 
 *
 */

//=====[Libraries]=============================================================
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "mqtt_conn.h"

//=====[Declaration of private defines]========================================
#define DELAY_WIFI 500
#define DELAY_MQTT 2000
#define SERIAL_BAUD 9600
#define MSG_BUFFER_SIZE 15

//=====[Declaration and initialization of public global objects]===============
static WiFiClient espClient;
static PubSubClient client(espClient);

//=====[Declaration and initialization of public global variables]=============
String mqttDataString;
bool mqttMessageReceived;

//=====[Declarations (prototypes) of private functions]========================
static void smartHomeWiFiConnect();
static void smartHomeWiFiSuccess();
static void smartHomeMqttConnect();
static void smartHomeMqttCallback(char* topic, byte* payload, unsigned int length);

//=====[Implementations of private functions]==================================
static void smartHomeWiFiConnect() {
  bool ledStatus = false;
  while (WiFi.status() != WL_CONNECTED) {
    delay(DELAY_WIFI);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, ledStatus);
    ledStatus = !ledStatus;
  }
  smartHomeWiFiSuccess();
}

static void smartHomeWiFiSuccess() {
  Serial.print("\nConectado a:\t");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, HIGH);
}

static void smartHomeMqttConnect() {

  String esp32_mac = WiFi.macAddress();
  const char* mqtt_id = esp32_mac.c_str();

  while (!client.connected()) {
    Serial.print("Conectar al broker MQTT con ID: ");
    Serial.println(mqtt_id);
    if (client.connect(mqtt_id)) {
      Serial.println("... Conectado!");
    } else {
      Serial.print("... Fallo, error=");
      Serial.print(client.state());
      Serial.println(" intentando nuevamente en 2 segundos");
      delay(DELAY_MQTT);
    }
  }
}

static void smartHomeMqttCallback(char* topic, byte* payload, unsigned int length) {
  String message = String((char*)payload).substring(0, length);
  mqttDataString = String(topic) + ":" + message;  // "topic:payload"
  mqttMessageReceived = true;
}

//=====[Implementations of public functions]===================================
void smartHomeInit() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
}

void smartHomeWifiInit(const char* ssid, const char* password) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Conectando a:\t");
  Serial.println(ssid);
  smartHomeWiFiConnect();
}

void smartHomeMqttInit(const char* server, const int port) {
  client.setServer(server, port);
  client.setKeepAlive(30);
  client.setCallback(smartHomeMqttCallback);
  smartHomeMqttConnect();
}

void smartHomeMqttSubscribe(const char* topic) {
  client.subscribe(topic);
}

void smartHomeMqttPublish(const char* topic, const char* payload) {
  client.publish(topic, payload);
}

void smartHomeMqttPublish(const char* topic, int payload) {
  char mqtt_mensaje[MSG_BUFFER_SIZE];
  snprintf(mqtt_mensaje, MSG_BUFFER_SIZE, "%d", payload);
  client.publish(topic, mqtt_mensaje);
}

void smartHomeMqttPublish(const char* topic, bool payload) {
  const char* mqtt_mensaje = payload ? "true" : "false";
  client.publish(topic, mqtt_mensaje);
}

void smartHomeMqttPublish(const char* topic, float payload) {
  char mqtt_mensaje[MSG_BUFFER_SIZE];
  snprintf(mqtt_mensaje, MSG_BUFFER_SIZE, "%.2f", payload);
  client.publish(topic, mqtt_mensaje);
}

void smartHomeMqttLoop() {
  if (!client.connected()) smartHomeMqttConnect();
  client.loop();
}

bool smartHomeDelay(int time) {

  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= time) {
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}
