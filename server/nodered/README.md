# Node-RED

[Node-RED](https://nodered.org/) es una herramienta de programación para conectar dispositivos de hardware, APIs y servicios en línea de formas nuevas e interesantes. Proporciona un editor basado en navegador que facilita la conexión de flujos utilizando una amplia gama de nodos.

Node-RED se basa en [Node.js](https://nodejs.org/) y aprovecha al máximo su modelo sin bloqueo impulsado por eventos. Esto lo hace ideal para ejecutarse en hardware de bajo costo como computadoras Raspberry Pi.

## Instalación

La guía de instalación oficial [Getting Started](https://nodered.org/docs/getting-started/raspberrypi) tiene los pasos a seguir para instalar y actualizar Node-RED.

Hay que descargar y ejecutar un script que está alojado en [Github](https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered).

```bash
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
```

Para correr el script, es posible que sea necesario instalar algunas dependencias:

```bash
sudo apt install build-essential git curl
```

## Ejecutar Node-RED localmente

En el terminal utilizar el comando `node-red` para ejecutar Node-RED. Para detenerlo, presionar `Ctrl-C`.

Debido a la memoria limitada de la Raspberry Pi, es recomendable utilizar Node-RED con un argumento adicional para que se libere memoria no utilizada:

```bash
node-red-pi --max-old-space-size=256
```

## Ejecutar Node-RED como un servicio

El script de instalación establece Node-RED para funcionar como un servicio. Los siguientes comandos permiten trabajar con el servicio:

- `node-red-start` inicia el servicio. Presionar `Ctrl-C` para cerrar la ventana no detiene el servicio.
- `node-red-stop` detiene el servicio.
- `node-red-restart` reinicia el servicio.
- `node-red-log` muestra la salida de registro del servicio.

## Ejecutar Node-RED al inicio (autostart)

Es posible habilitar el servicio para que inicie al encender la Raspberry Pi:

```bash
sudo systemctl enable nodered.service
```

Para desactivar el servicio, ejecutar:

```bash
sudo systemctl disable nodered.service
```

## Abrir el editor

Una vez que Node-RED se esta ejecutando, se puede acceder al editor en un navegador abriendo la dirección: `http://localhost:1880`.