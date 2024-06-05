/*
  Ejemplo de uso de comunicación RS-485 para enviar valores
  de temperatura y humedad adquiridos por un sensor de bajo
  costo DHT11.

  Utiliza la librería SoftwareSerial para emular un puerto
  serie en los pines 6 y 5 de un Arduino Uno.

      SN75176
     +----U-----+
  RO | 1      8 | Vcc
  RE | 2      7 | B
  DE | 3      6 | A
  DI | 4      5 | Gnd
     +----------+

  RO  - Receiver out
  RE  - Receiver enable (enabled when this pin is LOW)
  DE  - Driver   enable (enabled when this pin is HIGH)
  DI  - Driver   in (the transmitter pin)
  GND - Ground (0V)
  A   - Connect to pin A of the other 485 IC
  B   - Connect to pin B of the other 485 IC
  Vcc - Power (Vcc)

*/

#include <SoftwareSerial.h>
#include "DHT.h"

const int RO = 5;
const int DI = 6;
const int DHT_PIN = 2;
const int SELECT = 7;

SoftwareSerial portSerial(DI, RO); //RX, TX
DHT dht(DHT_PIN, DHT11);

void setup() {

  // Pines RE/DE, para enviar datos deberemos escribir un
  // estado alto, mientras que para recibir deberemos escribir
  // un estado bajo.
  pinMode(SELECT, OUTPUT);
  digitalWrite(SELECT, HIGH);

  // Configurar la velocidad del puerto SoftwareSerial
  portSerial.begin(9600);
  portSerial.println("Pruebas RS-485");
  
  // Inicia el sensor DHT11
  dht.begin();
}

void loop() {

  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  portSerial.print("Humedad: ");
  portSerial.print(humedad);
  portSerial.print(" - Temperatura: ");
  portSerial.println(temperatura);
  delay(2000);
}
