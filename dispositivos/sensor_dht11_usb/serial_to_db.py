# Implementación de Puerto Serie a MySQL/MariaDB
# Creado 09/06/2022
# Modificado 17/05/2024

import serial, mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="password"
)
mycursor = mydb.cursor()
mycursor.execute("USE arduino")

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
  
  # Consultas a la base de datos
  sql = "INSERT INTO sensores (idSensor, humedad, temperatura) VALUES (%s, %s, %s)"
  valores = (id_sensor, hume, temp)
  mycursor.execute(sql, valores)
  mydb.commit()
  print(mycursor.rowcount, "registro insertado.")
