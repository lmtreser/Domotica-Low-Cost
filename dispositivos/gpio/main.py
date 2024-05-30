# Leer datos de temperatura y humedad desde un sensor DHT11
# e insertarlos en una base de datos
# 
# Necesita los siguientes modulos: datetime, time, 
# Adafruit_DHT (pip install Adafruit_DHT) y
# MySQLdb (pip install mysql-connector-python)
#

#!/usr/bin/env python3

from datetime import datetime
import mysql.connector, Adafruit_DHT, os, time

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

# Obtener fecha y hora actual y formatearla
def timestamp():
    clock_now = datetime.now()
    clock = clock_now.strftime('%Y-%m-%d %H:%M:%S')
    return clock

def sensor(tipo, gpio):
    humedad, temperatura = Adafruit_DHT.read_retry(tipo, gpio)
    # No se utiliza la humedad en este ejemplo
    return temperatura
    
# Funcion principal
def main():
    try:
        while True:
                        
            # Obtener datos y almacenar en la db
            tiempo = timestamp()
            temperatura = sensor(tipo, gpio)
            insert(3, 'Activacion', temperatura, tiempo)
            
            # Registrar los eventos en un log
            file = open("dht11.log","a")
            file.write(str(tiempo) + " - ")
            file.write(str(temperatura) + " °C - ")
            file.write(str(mycursor.rowcount) + " registro insertado en la db.\n")
            file.close()
            
            time.sleep(5)

    except KeyboardInterrupt:
        print("\nInterrupción de teclado. Saliendo...")
        mydb.close()

if __name__ == "__main__":
    main()
