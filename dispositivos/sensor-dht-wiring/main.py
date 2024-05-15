# Leer datos de temperatura y humedad desde un sensor DHT11
# e insertarlos en una base de datos
# 
# Necesita los siguientes modulos: datetime, time, 
# Adafruit_DHT (pip install Adafruit_DHT) y
# MySQLdb (pip install mysql-connector-python)
#

#!/usr/bin/env python3

from datetime import datetime
import mysql.connector
import Adafruit_DHT
import time

# Configurar conexion a la base de datos
mydb = mysql.connector.connect(
  host="localhost",
  user="adminrpi",
  password="adminrpi"
)
mycursor = mydb.cursor()
mycursor.execute("USE domotica")

# Configurar el sensor (DHT11) y GPIO23 (pin 16)
tipo = Adafruit_DHT.DHT11 
gpio = 23

# Insertar un registro
def insert(id, evento, valor, time):
    sql = "INSERT INTO Eventos (ID_Dispositivo, Tipo, Valor, Fecha_Hora) VALUES (%s, %s, %s, %s)"
    datos = (id, evento, valor, time)
    mycursor.execute(sql, datos)
    mydb.commit()
    print(mycursor.rowcount, "registros insertados.")

# Obtener fecha y hora actual y formatearla
def timestamp():
    clock_now = datetime.now()
    clock = clock_now.strftime('%Y-%m-%d %H:%M:%S')
    return clock

def sensor(tipo, gpio):
    humedad, temperatura = Adafruit_DHT.read_retry(tipo, gpio)
    return temperatura
    
# Funcion principal
def main():
    while True:
        tiempo = timestamp()
        temperatura = sensor(tipo, gpio)
        insert(3, 'Activacion', temperatura, tiempo)
        time.sleep(5)

if __name__ == "__main__":
    main()
