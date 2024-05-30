# Sensor DHT11 Raspberry Pi Wiring

Construcción de un sensor de humedad y temperatura mediante el DHT11. Se utiliza conectado directamente a los GPIOs de la placa Raspberry Pi 3B.

- `Adafruit_DHT-1.4.0.tar.gz` Módulo Python para comunicarse con el sensor
- `RPI DHT11.fzz` Diagrama pictórico (Fritzing)
- `RPI+DHT11.jpg` Foto del prototipo
- `RPI DHT11.png` Diagrama pictórico
- `main.py` Leer datos desde un sensor DHT11 e insertarlos en una base de datos
- `sensor.py` Leer datos de temperatura y humedad desde el sensor DHT11

## Dependencias

`main.py` necesita las siguientes dependencias: `datetime`, `time`, `Adafruit_DHT` y `MySQLdb`. Para instalarlas, desde el terminal:

```bash
pip install Adafruit_DHT mysql-connector-python
```

`sensor.py` necesita las siguientes dependencias: `time` y `Adafruit_DHT`. Para instalarlas, desde el terminal:

```bash
pip install Adafruit_DHT mysql-connector-python
```
