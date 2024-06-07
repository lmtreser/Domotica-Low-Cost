# Detección de Colores con MicroPython
#
# Para realizar la detección de colores, podes usar técnicas básicas de procesamiento
# de imágenes. Este ejemplo permite detectar un color específico en la imagen.
# Capturar y Procesar la Imagen:

import esp
import machine
import time
import camera
import ustruct
import gc

# Inicializar la cámara
camera.init(0, format=camera.GRAYSCALE, fb_location=camera.PSRAM)

# Capturar una imagen
buf = camera.capture()

# Procesar la imagen
def detect_color(image, threshold):
    width = 320  # Asumiendo una resolución de 320x240
    height = 240
    count = 0
    
    for y in range(height):
        for x in range(width):
            # Obtener el índice del píxel
            index = y * width + x
            pixel = image[index]

            # Verificar si el píxel está dentro del umbral de color
            if pixel > threshold:
                count += 1

    return count

# Configurar un umbral para la detección de color
color_threshold = 200
detected_pixels = detect_color(buf, color_threshold)

print("Número de píxeles detectados:", detected_pixels)

# Finalizar la cámara
camera.deinit()
