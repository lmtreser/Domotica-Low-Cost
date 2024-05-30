/*  Enviar datos por puerto serie de un sensor DHT11
    para ser capturados por un script Python
    
    Creado 09/06/2022
    Modificado 16/05/2024

    Necesita la biblioteca DHT Sensor de Adafruit
    https://github.com/adafruit/DHT-sensor-library

*/

#include "DHT.h"

const int DHTPIN = 2;
const int DHTTYPE = DHT11;
const int ID = 2;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  Serial.print(ID);
  Serial.print(",");
  Serial.print(humedad);
  Serial.print(",");
  Serial.println(temperatura);
  delay(3000);
}
