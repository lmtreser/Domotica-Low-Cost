# Sensor DHT11 USB

Construcción de un sensor de humedad y temperatura mediante el DHT11. Utiliza comunicación cableada mediante USB.

- `sensor_dht11_usb.ino` Arduino Sketch
- `RPI USB DHT11.fzz` Diagrama pictórico (Fritzing)
- `ARDUINO+DHT11.jpg` Foto del prototipo
- `RPI USB DHT11.png` Diagrama pictórico
- `from_serial.py` Script para capturar y mostrar los datos

## Dependencias

`sensor_dht11_usb.ino` necesita la biblioteca *DHT Sensor de Adafruit*, se puede descargar desde el [repositorio](https://github.com/adafruit/DHT-sensor-library).

`from_serial.py` necesita el modulo *PySerial*, se puede instalar desde el terminal:

```bash
pip install pyserial
```
