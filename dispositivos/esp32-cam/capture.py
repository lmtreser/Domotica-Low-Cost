# Código para Capturar una Imagen

import esp
import machine
import time
import camera

# Inicializar la cámara
camera.init(0, format=camera.JPEG, fb_location=camera.PSRAM)

# Capturar una imagen
buf = camera.capture()

# Guardar la imagen en un archivo
with open("/sd/captura.jpg", "wb") as f:
    f.write(buf)

print("Imagen guardada como captura.jpg")

# Finalizar la cámara
camera.deinit()
