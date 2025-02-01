/**
 * @mainpage 
 * @brief Manejo de conectividad WiFi y MQTT
 * @date created 18 Sep 2024
 * @author Lucas Martin Treser (github: @lmtreser)
 * @file mqtt_conn.h
 *
 * Funciones útiles para la gestión de la 
 * conexión e intercambio de mensajes con 
 * el broker MQTT.
 * 
 * Utiliza la biblioteca "PubSubClient" de Nick O’Leary
 * disponible en https://github.com/knolleary/pubsubclient
 *
**/

//=====[#include guards - begin]===============================================
#ifndef MQTT_CONN_H
#define MQTT_CONN_H

//=====[Declaration and initialization of public global variables]=============
extern String mqttDataString;     /// String global, almacena topic:payload
extern bool mqttMessageReceived;  /// Flag global, ejecución del callback mqtt

//=====[Declarations (prototypes) of public functions]=========================

/**
 * @brief Inicializa pines y Serial
**/
void smartHomeInit();

/**
 * @brief Inicializa la conexión WiFi
 * @param ssid string con el nombre de la red WiFi
 * @param password string con la contraseña de la red WiFi
**/
void smartHomeWifiInit(const char* ssid, const char* password);

/**
 * @brief Inicializa la conexión al broker MQTT
 * @param server string con la IP del broker 
 * @param port puerto del broker
**/
void smartHomeMqttInit(const char* server, const int port);

/**
 * @brief Subscripción a topics MQTT
 * @param topic string con el topic a subscribirse
**/
void smartHomeMqttSubscribe(const char* topic);

/**
 * @brief Publicación de mensajes en un topic MQTT
 * @param topic string con el topic a publicar
 * @param payload string con el mensaje a publicar, acepta
                  los siguientes tipos de datos: char, int, 
                  bool y float
**/
void smartHomeMqttPublish(const char* topic, const char* payload);
void smartHomeMqttPublish(const char* topic, int payload);
void smartHomeMqttPublish(const char* topic, bool payload);
void smartHomeMqttPublish(const char* topic, float payload);

/**
 * @brief Loop de la conexión MQTT, intenta la reconexión
          en caso de perder la misma, ejecuta funciones de la
          biblioteca PubSub
**/
void smartHomeMqttLoop();

/**
 * @brief Retardo no bloqueante
 * @param time entero con tiempo a esperar
 * @return finalizado time, devuelve true
**/
bool smartHomeDelay(int time);

//=====[#include guards - end]=================================================
#endif