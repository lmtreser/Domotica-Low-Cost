# Sensor DHT11 USB

Construcción de un sensor de humedad y temperatura mediante el DHT11. Utiliza comunicación cableada mediante USB.

- `sensor_dht11_usb.ino` Arduino Sketch
- `arduino.sql` Consultas para creación de base de datos MySQL/MariaDB
- `RPI USB DHT11.fzz` Diagrama pictórico (Fritzing)
- `ARDUINO+DHT11.jpg` Foto del prototipo
- `RPI USB DHT11.png` Diagrama pictórico
- `from_serial.py` Script para capturar y mostrar los datos
- `serial_to_db.py` Script para capturar y almacenar datos en MySQL/MariaDB

## Dependencias

`sensor_dht11_usb.ino` necesita la biblioteca *DHT Sensor de Adafruit*, se puede descargar desde el [repositorio](https://github.com/adafruit/DHT-sensor-library).

`from_serial.py` necesita el modulo *PySerial*, se puede instalar desde el terminal:

```bash
pip install pyserial
```

`serial_to_db.py` necesita los modulos *PySerial* y *MySQLdb*, se pueden instalar desde el terminal:

```bash
pip pyserial mysql.connector
```
