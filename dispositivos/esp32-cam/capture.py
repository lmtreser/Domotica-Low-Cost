# Código para Capturar una Imagen
# https://lemariva.com/blog/2020/06/micropython-support-cameras-m5camera-esp32-cam-etc

import esp
import machine
import time
import camera

# Inicializar la cámara
camera.init(0, format=camera.JPEG)

# Capturar una imagen
buf = camera.capture()

# Guardar la imagen en un archivo
#with open("captura.jpg", "wb") as f:
#    f.write(buf)

print("Imagen guardada como captura.jpg")

# Finalizar la cámara
camera.deinit()
