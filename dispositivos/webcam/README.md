# WebCam

Acceso a una webcam conectada vía USB.

- `webcam.py` Script para sacar una fotografía

## Dependencias

Para funcionar necesita la biblioteca [OpenCV](https://opencv.org/). Se trata de una biblioteca de visión por computadora, de código abierto, que contiene más de 2500 algoritmos. Para instalar el módulo:

```bash
pip install opencv-python
```

Es de utilidad también disponer del paquete [V4l-utils](https://linuxtv.org/wiki/index.php/V4l-utils), que permite manejar dispositivos multimedia.

Para instalar:

```bash
sudo apt install v4l-utils
```

Para buscar cámaras disponibles:

```bash
v4l2-ctl --list-devices
```

## Problemas conocidos

Puede ocurrir que el usuario no pueda acceder a la webcam, en tal caso, hay que agregarlo al grupo correspondiente:

```bash
sudo usermod -aG video $USER
```
