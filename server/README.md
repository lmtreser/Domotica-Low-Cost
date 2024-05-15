# Servidor

El servidor está basado en una placa [Raspberry Pi 3 Model B](https://www.raspberrypi.com/products/raspberry-pi-3-model-b/) y corre el sistema operativo [Raspberry Pi OS](https://www.raspberrypi.com/software/) basado en Debian GNU/Linux.

![Raspberry Pi 3 Model B](./RPI3B.jpg)

El pinout del conector [GPIO de 40 pines](https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#gpio-and-the-40-pin-header) es el siguiente:

![GPIO and the 40-pin header](./RPI GPIO Pinout Diagram.png)

## Software necesario

El servidor ejecuta una serie de servicios para diferentes tareas del sistemas domótico, algunos paquetes se instalan por defecto junto al sistema operativo, y otros hay que hacerlo manualmente. A saber:

- [Python](https://www.python.org/)
- [Package Installer for Python (PIP)](https://pip.pypa.io/)
- [MariaDB Server](https://mariadb.org/)

```Bash
sudo apt install pip mariadb-server
```

## Acceso remoto

Para poder administrar el servidor, se puede [acceder de forma remota](https://www.luisllamas.es/raspberry-pi-ssh/) a través de un terminal como [PuTTY](https://www.putty.org/) usando SSH.

```bash
ssh usuario@host
```

Para copiar archivos o directorios desde local a remoto:

```bash
scp /ruta/archivo usuario@host:/ruta/
```

Para copiar archivos o directorios desde remoto a local:

```bash
scp usuario@host:/ruta/ /ruta/archivo
```

## Iniciar un Python script al bootear

Para hacer que un script se ejecute automáticamente al iniciar la Raspberry Pi, hay que agregarlo al archivo `rc.local`:

```bash
sudo nano /etc/rc.local
python3 /ruta/al/script.py &
sudo reboot
```

En caso de utilizar `systemd` en lugar de `rc.local` para ejecutar tu script al iniciar el sistema en una Raspberry Pi, hay que crear un servicio systemd:

1. Crear un archivo de servicio para el script. Por ejemplo, crear un archivo `miprograma.service` en `/etc/systemd/system/`:

```bash
sudo nano /etc/systemd/system/miprograma.service
```

2. Definir el servicio:

```
[Unit]
Description=Mi programa
After=multi-user.target

[Service]
Type=simple
ExecStart=/usr/bin/python3 /ruta/a/tu/script.py
Restart=always

[Install]
WantedBy=multi-user.target
```

3. Recargar la configuración de systemd para que reconozca el nuevo servicio:

```bash
sudo systemctl daemon-reload
```

4. Habilitar el servicio para que se inicie automáticamente en el arranque:

```bash
sudo systemctl enable miprograma.service
```

5. Iniciar el servicio:

```bash
sudo systemctl start miprograma.service
```
