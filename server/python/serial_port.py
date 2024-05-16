# Leer datos desde el puerto serie
#
# Necesita el el modulo PySerial
# https://pypi.org/project/pyserial/
# Instalar: pip3 install pyserial
#

import serial

# Abrir el puerto serie a 9600 baudios
serialPort = serial.Serial('/dev/ttyUSB0', 9600)

while True:
  # Leer hasta encontar el final de linea (\n)
  datos = serialPort.readline()
  print(datos.decode('utf-8'))