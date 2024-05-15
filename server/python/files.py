# Uso del sistema de archivos con Python
# Creado 15/05/2024
#
# open: abre un archivo para leer (r) o escribir (w)
# write: escribe texto en el archivo
# read: lee el archivo completo
# readline: lee una línea del archivo

import os

file = open("archivo.log", "w")

# Escribir información en un archivo
file.write("Lorem Ipsum")
file.close()

# El modo "a" (append) abre el archivo para agregar datos al final
file = open("archivo.log","a")
file.write(" is simply dummy text \n")
file.write("of the printing and typesetting industry.")
file.close()

# Leer el contenido de un archivo
file = open("archivo.log", "r")
contenido = file.read()
print(contenido)
