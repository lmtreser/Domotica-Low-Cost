# Captura de fotos con ESP32CAM
# Creado el 7 de junio de 2024

import camera
import machine
from time import sleep

flash = machine.Pin(4, machine.Pin.OUT)

foto_count = 1

while (True):
    
    nombre = "IMG"+str(foto_count)+".jpg"
    print(nombre)
    
    try:
        camera.init(0, format=camera.JPEG, fb_location=camera.PSRAM)
        camera.framesize(camera.FRAME_VGA)

        flash.value(1)
        sleep (0.5)

        # Captura la imagen
        img = camera.capture()
        print("Tamaño=",len(img))
        
        flash.value(0)
        camera.deinit ()
       
        # Guardar la imagen en el sistema de archivos
        imgFile = open(nombre, "wb")
        imgFile.write(img)
        imgFile.close()
        
        foto_count += 1
        
        sleep (10)
        
    except Exception as err:
    
        print("Error= "+str (err))
        sleep(2)