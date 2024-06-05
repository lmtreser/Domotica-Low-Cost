# Dispositivo con ESP32-CAM

Dispositivo base para trabajar con ESP32-CAM.

- `micropython-camera-driver` Repositorio de Mauro Riva
- `OV2640.pdf` Datasheet OV2640 Color CMOS UXGA (2.0 MegaPixel) CAMERACHIP
- `ESP32-CAM Pinout.jpg` Pinout de la placa ESP32-CAM
- `FTDI.png` Conexión adaptador USB
- `capture.py` Script para capturar una fotografía
- `process.py` Script para detectar colores

## Firmware

La placa ESP32-CAM se puede utilizar con MicroPython. Utilizaremos el driver `micropython-camera-driver` de [Mauro Riva](https://github.com/lemariva). Se puede descargar desde el repositorio en [GitHub](https://github.com/lemariva/micropython-camera-driver).

Como la placa no posee conexión USB, hay que utilizar un adaptador USB-TTL. Las conexiones son las que muestra la imagen.

![Conexiones FTDI <> ESP32-CAM](./FTDI.png)

Para instalarlo:

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash
```

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash -z 0x1000 micropython_camera_feeeb5ea3_esp32_idf4_4.bin
```

## Pinout

![Pinout ESP32-CAM](./ESP32-CAM%20Pinout.jpg)

| GPIO      | Dispositivo               | Función               |
| --------- | ------------------------- | --------------------- |
| GPIO 0    |                           | Flashing mode = LOW   |
| GPIO 4    | LED Flash                 | LED de iluminación    |
| GPIO 33   | LED Builtin               | LED de uso general    |
|           |                           |                       |
| GPIO 1    | UART TX                   | Comunicación serie    |
| GPIO 2    | UART RX                   | Comunicación serie    |
|           |                           |                       |
| GPIO14    | SDA                       | Protocolo I2C         |
| GPIO15    | SCL                       | Protocolo I2C         |
|           |                           |                       |
| GPIO 14   | CLK                       | MicroSD               |
| GPIO 15   | CMD                       | MicroSD               |
| GPIO 2    | DATA0                     | MicroSD               |
| GPIO 4    | DATA1/FLASH               | MicroSD               |
| GPIO 12   | DATA2                     | MicroSD               |
| GPIO 13   | DATA3                     | MicroSD               |
|           |                           |                       |
| GPIO 5    | D0 Y2_GPIO_NUM            | OV2640                |
| GPIO 18   | D1 Y3_GPIO_NUM            | OV2640                |
| GPIO 19   | D2 Y4_GPIO_NUM            | OV2640                |
| GPIO 21   | D3 Y5_GPIO_NUM            | OV2640                |
| GPIO 36   | D4 Y6_GPIO_NUM            | OV2640                |
| GPIO 39   | D5 Y7_GPIO_NUM            | OV2640                |
| GPIO 34   | D6 Y8_GPIO_NUM            | OV2640                |
| GPIO 35   | D7 Y9_GPIO_NUM            | OV2640                |
| GPIO 0    | XCLK XCLK_GPIO_NUM        | OV2640                |
| GPIO 22   | PCLK PCLK_GPIO_NUM        | OV2640                |
| GPIO 25   | VSYNC VSYNC_GPIO_NUM      | OV2640                |
| GPIO 23   | HREF HREF_GPIO_NUM        | OV2640                |
| GPIO 26   | SDA SIOD_GPIO_NUM         | OV2640                |
| GPIO 27   | SCL SIOC_GPIO_NUM         | OV2640                |
| GPIO 32   | POWER PIN PWDN_GPIO_NUM   | OV2640                |

## Recursos

- [Aprende a programar la ESP32-CAM en Micropython. Parte 1](https://www.profetolocka.com.ar/2022/04/18/aprende-a-programar-la-esp32-cam-en-micropython-parte-1/)
- [Aprende a programar la ESP32-CAM en Micropython. Parte 2](https://www.profetolocka.com.ar/2022/04/25/aprende-a-programar-la-esp32-cam-en-micropython-parte-2/)
- [ESP32 CAM introducción y primeros pasos](https://programarfacil.com/esp32/esp32-cam/)
- [ESP32-CAM: Machine Vision Tips, Camera Guides and Projects](https://www.arducam.com/esp32-machine-vision-learning-guide/)
