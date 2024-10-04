/*
  ModbusRTUSlave Software Serial

  Este ejemplo permite configurar y usar una placa Arduino UNO como dispositivo Modbus esclavo
  mediante Software Serial.
  Usa la biblioteca ModbusRTUSlave (https://github.com/CMB27/ModbusRTUSlave).

  Circuito:

  - Un LED integrado en el pin 13
  - Serial RX a pin 10 - RO de un conversor MAX485/SN75176
  - Serial TX a pin 11 - DI de un conversor MAX485/SN75176

  Trama de datos (master):

  ON:   02 05 00 00 FF 00 8C 09
  OFF:  02 05 00 00 00 00 CD F9

  Created: 2023-07-22
  By: C. M. Bulliner
  Modified: 2024-01-27
  By: C. M. Bulliner
  Modified: 2024-07-25
  By: L. M. Treser
  Last Modified: 2024-07-31
  By: L. M. Treser

*/

#include <SoftwareSerial.h>
#include <ModbusRTUSlave.h>

const uint8_t coilPin = 13;
const uint8_t dePin = 7;
const uint8_t rxPin = 10;
const uint8_t txPin = 11;
const uint8_t modbusId = 2;

SoftwareSerial mySerial(rxPin, txPin);
ModbusRTUSlave modbus(mySerial, dePin);

uint16_t inputRegisters[1];
bool coils[1];

void setup() {
  pinMode(coilPin, OUTPUT);
  modbus.configureInputRegisters(inputRegisters, 1);
  modbus.configureCoils(coils, 1);
  modbus.begin(modbusId, 9600);
}

void loop() {

  inputRegisters[0] = random(0, 30);
  modbus.poll();
  digitalWrite(coilPin, coils[0]);
}
