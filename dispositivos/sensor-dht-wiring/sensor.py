# Leer datos de temperatura y humedad
# desde un sensor DHT11/DHT22
# 
# Necesita el modulos Adafruit_DHT
# pip install Adafruit_DHT) y

import Adafruit_DHT
import time

# Tipo de sensor (DHT11) y GPIO23 (pin 16)
sensor = Adafruit_DHT.DHT11 
pin = 23

while True:
    
    # Leer los datos del sensor
    humedad, temperatura = Adafruit_DHT.read_retry(sensor, pin)

    # Si la lectura fue exitosa, muestra los datos
    if humedad is not None and temperatura is not None:
        print('Temperatura={0:0.1f}°C  Humedad={1:0.1f}%'.format(temperatura, humedad))
    else:
        print('Error al leer los datos desde el sensor.')

    time.sleep(2)
