# Dispositivo con ESP32-CAM

Dispositivo base para trabajar con ESP32-CAM.

- `micropython-camera-driver` Repositorio de Mauro Riva
- `OV2640.pdf` Datasheet OV2640 Color CMOS UXGA (2.0 MegaPixel) CAMERACHIP
- `ESP32-CAM Pinout.jpg` Pinout de la placa ESP32-CAM
- `capture.py` Script para capturar una fotografía
- `process.py` Script para detectar colores

## Firmware

La placa ESP32-CAM se puede utilizar con MicroPython. Utilizaremos el driver `micropython-camera-driver` de [Mauro Riva](https://github.com/lemariva). Se puede descargar desde el repositorio en [GitHub](https://github.com/lemariva/micropython-camera-driver).

Para instalarlo:

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash
```

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash -z 0x1000 micropython_camera_feeeb5ea3_esp32_idf4_4.bin
```

## Recursos

- [Aprende a programar la ESP32-CAM en Micropython. Parte 1](https://www.profetolocka.com.ar/2022/04/18/aprende-a-programar-la-esp32-cam-en-micropython-parte-1/)
- [Aprende a programar la ESP32-CAM en Micropython. Parte 2](https://www.profetolocka.com.ar/2022/04/25/aprende-a-programar-la-esp32-cam-en-micropython-parte-2/)
- [ESP32-CAM: Machine Vision Tips, Camera Guides and Projects](https://www.arducam.com/esp32-machine-vision-learning-guide/)
