# Leer datos desde el puerto serie

# Importamos el modulo PySerial
# pip3 install pyserial
# https://pypi.org/project/pyserial/
import serial

# Abrimos el puerto serie a 9600 baudios
serialPort = serial.Serial('/dev/ttyUSB0', 9600)

while True:
  # leemos hasta que encontarmos el final de linea
  datos = serialPort.readline()
  print(datos.decode('utf-8'))