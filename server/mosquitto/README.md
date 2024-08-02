# Eclipse Mosquitto

[Eclipse Mosquitto](https://mosquitto.org/) es un *message broker* de código abierto que implementa las versiones 3.1, 3.1.1 y 5.0 del protocolo MQTT. El proyecto Mosquitto también proporciona una biblioteca C para implementar clientes MQTT y los muy populares clientes MQTT de línea de comandos mosquitto_pub y mosquitto_sub.

El protocolo MQTT proporciona un método ligero para enviar mensajes utilizando un modelo de publicación/suscripción. Esto lo hace adecuado para mensajería de IoT, como sensores de baja potencia o dispositivos móviles como teléfonos, computadoras integradas o microcontroladores.

## Instalar Mosquitto

Para instalar Mosquitto, desde el terminal:

```bash
sudo apt install mosquitto mosquitto-clients
```

La configuración se almacena en el archivo `default.conf`. Para editarlo:

```bash
sudo nano /etc/mosquitto/conf.d/default.conf
```

En el caso de utilizar el broker sin seguridad, debemos escuchar el puerto `1883` y permitir logins anónimos. Agregar al archivo de configuración las siguientes líneas:

```bash
listener 1883
allow_anonymous true
```

Luego, reiniciar el servicio para que los cambios surtan efecto:

```bash
sudo systemctl restart mosquitto
```

Para securizar Mosquitto, consultar el archivo `How to Install and Secure the Mosquitto MQTT.pdf`.

## Probar Mosquitto

Para probar Mosquitto, abrir un terminal y lanzar `mosquitto_sub`:

```bash
mosquitto_sub -h localhost -t test_topic
```

Luego enviar un mensaje mediante `mosquitto_pub`:

```bash
mosquitto_pub -h localhost -t test_topic -m "Hello world!"
```

## Configurar la Autenticación

Si queremos habilitar la autenticación para el acceso al broker de Mosquitto, primero necesitamos configurar un archivo de contraseñas. Comenzamos instalando la herramienta `mosquitto_passwd`:

```bash
sudo apt install mosquitto
```

Luego, creamos un archivo de contraseñas con el siguiente comando:

```bash
sudo mosquitto_passwd -c /etc/mosquitto/pwfile username
```

Reemplazamos `username` con el nombre de usuario que deseamos. Se nos pedirá que ingresemos y confirmemos una contraseña. Una vez creado el archivo de contraseñas, editamos el archivo de configuración `/etc/mosquitto/mosquitto.conf` para agregar la siguiente línea:

```bash
password_file /etc/mosquitto/pwfile
```

Guardamos y cerramos el archivo, y luego reiniciamos Mosquitto para aplicar los cambios con el siguiente comando:

```bash
sudo systemctl restart mosquitto
```

## Mosquitto desde Python

Para trabajar con mosquitto desde Python, hay que satisfacer la siguiente dependencia: [paho-mqtt](https://pypi.org/project/paho-mqtt/)

 Para instalarla:

```bash
pip install paho-mqtt
```

Es recomendable leer la documentación que se encuentra en el sitio oficial.
