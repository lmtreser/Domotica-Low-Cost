# Servidor

El servidor está basado en una placa [Raspberry Pi 3 Model B](https://www.raspberrypi.com/products/raspberry-pi-3-model-b/) y corre el sistema operativo [Raspberry Pi OS](https://www.raspberrypi.com/software/) basado en Debian GNU/Linux.

![Raspberry Pi 3 Model B](./RPI3B.jpg)

El pinout del conector [GPIO de 40 pines](https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#gpio-and-the-40-pin-header) es el siguiente:

![GPIO and the 40-pin header](./RPI_GPIO_Pinout_Diagram.png)

## Software necesario

El servidor ejecuta una serie de servicios para diferentes tareas del sistemas domótico, algunos paquetes se instalan por defecto junto al sistema operativo, y otros hay que hacerlo manualmente. A saber:

- [Python](https://www.python.org/)
- [Package Installer for Python (PIP)](https://pip.pypa.io/)
- [GNU Nano](https://www.nano-editor.org/)
- [Git](https://git-scm.com/)

- [MariaDB Server](https://mariadb.org/)
- [Eclipse Mosquitto](https://mosquitto.org/)
- [Node-RED](https://nodered.org/)

- [Midnight Commander](https://midnight-commander.org/)
- [Fbi IMproved](https://www.nongnu.org/fbi-improved/)

```Bash
sudo apt install git pip fim mc mariadb-server
```

## Agregar un pulsador de apagado

Apagar la Raspberry Pi simplemente desconectando la fuente de alimentación puede ser dañino para la tarjeta y la microSD. Hay que utilizar un botón de apagado suave, como si se tratara de tu computadora de uso diario.

El botón se conecta en los GPIO 5 y 6:

![GPIO and the 40-pin header](./pi-shutdown-button.png)

Para activar esta funcionalidad hay que abrir el archivo `/boot/firmware/config.txt` y añadir la siguiente línea. Luego reiniciar.

```bash
dtoverlay=gpio-shutdown
```

## Acceso remoto

Para poder administrar el servidor, se puede [acceder de forma remota](https://www.luisllamas.es/raspberry-pi-ssh/) a través de un terminal como [PuTTY](https://www.putty.org/) usando SSH. SSH, o Secure Shell, es un protocolo de red criptográfico que trabaja con el puerto 22 y que proporciona una manera segura de acceder a un dispositivo remoto, cifrando todo el tráfico.

Habilitar el servicio SSH desde `raspi-config`:

```bash
sudo raspi-config
```

Ingresar al menú `3 Interface Options` y activar la opción `I2 SSH Enable/disable`.

Para acceder remotamente, en el terminal:

```bash
ssh usuario@host
```

También se puede autentificar mediante un par de claves SSH, una clave privada y una clave pública. La clave privada se mantiene segura en la máquina local, mientras que la clave pública se copia al servidor remoto.

```bash
ssh-keygen -t rsa
```

Para copiar la clave publica (`id_rsa.pub`) al servidor remoto, es decir, agregarla al archivo `~/.ssh/authorized_keys` del usuario remoto:

```bash
ssh-copy-id usuario@host
```

## Transferir archivos

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
## Agregar un directorio al PATH

Para agregar un directorio al PATH, para BASH:

```bash
nano ~/.bashrc
export PATH=$PATH:/ruta/a/tu/directorio
source ~/.bashrc
echo $PATH
```

Para agregar un directorio al PATH, para ZSH:

```bash
nano ~/.zshrc
export PATH=$PATH:/ruta/a/tu/directorio
source ~/.zshrc
echo $PATH
```

## Problemas conocidos

Problemas conocidos (y comunes) a la hora de instalar o utilizar paquetes bajo GNU/Linux.

### "externally-managed-environment" al usar pip3

Puede aparecer el mensaje de error *externally-managed-environment* al querer instalar un paquete con pip3:

```bash
error: externally-managed-environment

× This environment is externally managed
╰─> To install Python packages system-wide, try apt install
    python3-xyz, where xyz is the package you are trying to
    install.

    If you wish to install a non-Debian-packaged Python package,
    create a virtual environment using python3 -m venv path/to/venv.
    Then use path/to/venv/bin/python and path/to/venv/bin/pip. Make
    sure you have python3-full installed.

    If you wish to install a non-Debian packaged Python application,
    it may be easiest to use pipx install xyz, which will manage a
    virtual environment for you. Make sure you have pipx installed.

    See /usr/share/doc/python3.11/README.venv for more information.

note: If you believe this is a mistake, please contact your Python installation
or OS distribution provider. You can override this, at the risk of breaking your
Python installation or OS, by passing --break-system-packages.
hint: See PEP 668 for the detailed specification.
```

Solución: eliminar el archivo `EXTERNALLY-MANAGED` de tu instalación de Python del sistema:

```bash
sudo rm -rf /usr/lib/python3.11/EXTERNALLY-MANAGED
```
