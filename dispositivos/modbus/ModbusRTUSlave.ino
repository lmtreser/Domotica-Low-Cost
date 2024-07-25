/*
  ModbusRTUSlave

  Este ejemplo permite configurar y usar una placa Arduino MEGA como dispositivo Modbus esclavo.
  Usa la biblioteca ModbusRTUSlave (https://github.com/CMB27/ModbusRTUSlave).
  
  Circuito:

  - Un pulsador desde el pin 2 a GND
  - Un pulsador desde el pin 3 a GND
  - Un LED integrado en el pin 13
  - Un LED desde pin 12 a GND con una resistencia de 1K ohm en serie
  - Serial1 RX pin a DI de un conversor MAX485/SN75176
  - Serial1 TX pin a RO de un conversor MAX485/SN75176

  Created: 2023-07-22
  By: C. M. Bulliner
  Modified: 2024-01-27
  By: C. M. Bulliner
  Last Modified: 2024-07-25
  By: L. M. Treser

*/

#include <ModbusRTUSlave.h>

const uint8_t coilPins[2] = { 12, 13 };
const uint8_t discreteInputPins[2] = { 2, 3 };
const uint8_t dePin = 7;
const uint8_t modbusId = 2;

ModbusRTUSlave modbus(Serial1, dePin);

bool coils[2];
bool discreteInputs[2];
uint16_t inputRegisters[2];

void setup() {
  pinMode(coilPins[0], OUTPUT);
  pinMode(coilPins[1], OUTPUT);
  pinMode(discreteInputPins[0], INPUT_PULLUP);
  pinMode(discreteInputPins[1], INPUT_PULLUP);

  modbus.configureCoils(coils, 2);
  modbus.configureDiscreteInputs(discreteInputs, 2);
  modbus.configureInputRegisters(inputRegisters, 2);
  modbus.begin(modbusId, 38400);
}

void loop() {
  discreteInputs[0] = digitalRead(discreteInputPins[0]);
  discreteInputs[1] = digitalRead(discreteInputPins[1]);

  inputRegisters[0] = 14; // Valor random
  inputRegisters[1] = 23; // Valor random

  modbus.poll();

  digitalWrite(coilPins[0], coils[0]);
  digitalWrite(coilPins[1], coils[1]);
}
