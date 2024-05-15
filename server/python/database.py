# Conexion a una base de datos MySQL desde Python
#
# Creado 09/06/2022
# Modificado 15/05/2024
#
# Necesita el modulo MySQLdb (pip install mysql-connector-python)
# https://pypi.org/project/mysql-connector-python/

import mysql.connector

# Crear una conexion a la base de datos
mydb = mysql.connector.connect(
  host="localhost",
  user="adminrpi",
  password="adminrpi"
)

# Crear una variable que permitira realizar operaciones
mycursor = mydb.cursor()

# Ejecutar una consulta
mycursor.execute("USE domotica")

# Ejecutar una consulta para insertar un registro
sql = "INSERT INTO Eventos (ID_Dispositivo, Tipo, Valor, Fecha_Hora) VALUES (%s, %s, %s, %s)"
datos = (3, 'Activacion', 17, '2024-05-15 11:33:00')
mycursor.execute(sql, datos)

# Commitear los cambios
mydb.commit()
print(mycursor.rowcount, "registros insertados.")

# Ejecutar una consulta
mycursor.execute("SELECT * FROM Eventos")
myresult = mycursor.fetchall()

# Imprimir los registros
for x in myresult:
  print(x)
  
# Cerrar la conexion
mydb.close()