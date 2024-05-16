# Lectura de datos desde el Puerto Serie (USB)
#
# Creado 09/06/2022
# Modificado 16/05/2024
#
# Utiliza el modulo PySerial
# pip install pyserial
#

import serial

serialPort = serial.Serial('/dev/ttyUSB0', 9600)

while True:
  
  # Recepcion y decodificacion de datos 
  datos = serialPort.readline()
  datos_raw = datos.decode('utf-8')
  
  # Separacion de datos
  id_sensor = datos_raw[0]
  hume = datos_raw[2:7]
  temp = datos_raw[8:13]
  
  print("raw: ", datos_raw)
  print ("id:", id_sensor, " humedad: ", hume, " temperatura: ", temp)
