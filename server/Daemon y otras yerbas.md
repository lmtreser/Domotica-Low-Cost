# Daemon y otras yerbas

Desde la web de Luis Llamas dos tutoriales sobre demonios y scripts al inicio. Se puede consultar la fuente original en [1](https://www.luisllamas.es/como-usar-y-crear-daemon-en-raspberry-pi/) y [2](https://www.luisllamas.es/comoejecutar-aplicacion-al-arranque-de-una-raspberry-pi/).

## Cómo usar y crear Daemon en Raspberry Pi

En sistemas Unix y Linux, un daemon (o “demonio” en español) es un proceso que se ejecuta en segundo plano y no está asociado a una interfaz de usuario directa. Estos procesos suelen iniciarse durante el arranque del sistema y continúan ejecutándose hasta que el sistema se apaga. Los daemons realizan tareas esenciales, como la gestión de servicios de red, el manejo de solicitudes de impresión o la supervisión de recursos del sistema.

### Cómo Funcionan los Daemons

Un daemon generalmente sigue estos pasos para funcionar:

- Inicialización: El daemon se inicia al arrancar el sistema o cuando se solicita explícitamente. Puede iniciarse desde un script de inicio, como `systemd`, o a través de un archivo de configuración en `/etc/init.d/`.

- Desprendimiento del Terminal: El daemon se desacopla de la terminal que lo inició. Esto implica que el proceso se ejecuta en segundo plano y no está vinculado a una sesión de usuario específica.

- Ejecución Continua: Una vez en ejecución, el daemon sigue funcionando y realizando su tarea específica. No requiere intervención del usuario y puede operar incluso si no hay usuarios conectados.

- Terminación: Los daemons pueden finalizarse de diversas maneras, ya sea por el apagado del sistema, mediante un comando específico o cuando se encuentra un error crítico.

### Cómo usar Daemons en Raspberry Pi

En Raspberry Pi OS, que usa `systemd` para gestionar servicios. `systemd` es un sistema de gestión de servicios utilizado en muchas distribuciones modernas de Linux. Permite iniciar, detener, habilitar y supervisar servicios del sistema. Puedes usar los siguientes comandos para controlar daemons:

Iniciar un Daemon:

```bash
sudo systemctl start nombre_del_servicio
```

Detener un Daemon:

```bash
sudo systemctl stop nombre_del_servicio
```

Reiniciar un Daemon:

```bash
sudo systemctl restart nombre_del_servicio
```

Habilitar un Daemon para que se inicie automáticamente en el arranque:

```bash
sudo systemctl enable nombre_del_servicio
```

Deshabilitar un Daemon para que no se inicie automáticamente:

```bash
sudo systemctl disable nombre_del_servicio
```

Verificar el estado de un Daemon:

```bash
sudo systemctl status nombre_del_servicio
```

Resolución de problemas. Para diagnosticar problemas con un daemon, revisa los logs:

```bash
journalctl -u nombre_del_servicio
```

### Crear un Daemon personalizado

Si deseas crear un Daemon personalizado, necesitas definir un archivo de servicio para `systemd`. Primero, debes crear un archivo de servicio que definirá la configuración del mismo. Para ello, abre un editor de texto con permisos de superusuario:

```bash
sudo nano /etc/systemd/system/mi_daemon.service
```

En este archivo, se define el comportamiento del servicio. A continuación, añadimos la configuración necesaria. En el archivo `mi_daemon.service`, añade la siguiente configuración:

```bash
[Unit]
Description=Mi Daemon Personalizado

[Service]
ExecStart=/ruta/al/ejecutable
Restart=always

[Install]
WantedBy=multi-user.target
```

- `[Unit]`: Sección que proporciona la descripción del servicio.
- `Description`: Breve descripción del servicio.
- `[Service]`: Sección que define cómo debe comportarse el servicio.
- `ExecStart`: Ruta completa al ejecutable del daemon.
- `Restart`: Define la política de reinicio del servicio; `always` reiniciará el servicio si se detiene inesperadamente.
- `[Install]`: Sección que especifica las condiciones para habilitar el servicio.
- `WantedBy`: Define el objetivo (target) al cual pertenece este servicio; `multi-user.target` es el equivalente a runlevel 3, es decir, un sistema con interfaz multiusuario sin GUI.

Después de crear o modificar un archivo de servicio, es necesario recargar `systemd` para que lea la nueva configuración:

```bash
sudo systemctl daemon-reload
```

Ahora puedes iniciar el servicio y hacer que se inicie automáticamente al arrancar el sistema:

```bash
sudo systemctl start mi_daemon
sudo systemctl enable mi_daemon
```

- `start`: Inicia el servicio inmediatamente.
- `enable`: Habilita el servicio para que se inicie automáticamente al arrancar el sistema.

Para asegurarte de que el servicio se está ejecutando correctamente, puedes verificar su estado con el siguiente comando:

```bash
sudo systemctl status mi_daemon
```

Este comando mostrará el estado actual del servicio, así como cualquier error o mensaje de registro que pueda ayudarte a diagnosticar problemas.

___

## Cómo ejecutar una aplicación al arrancar Raspberry Pi

Aprender a ejecutar aplicaciones automáticamente al arranque es una algo muy importante en una gran cantidad de proyectos con Raspberry Pi. Por ejemplo, porque quieres iniciar un servidor web, una aplicación personalizada o un script. O incluso conectarnos con un dispositivo físico, como una pantalla, un sensor, un actuador.

Existen varias opciones para configurar tu Raspberry Pi de manera que ejecute estas aplicaciones automáticamente cada vez que se inicie. Aquí tenéis una tabla con diferentes opciones para lograrlo.

| Método   | Descripción                                                     |
|----------|-----------------------------------------------------------------|
| rc.local | Método sencillo pero menos flexible                             |
| systemd  | Ofrece un control más detallado                                 |
| Autostart| Perfecto para aplicaciones gráficas en el entorno de escritorio |
| cron     | Buena opción para scripts simples y tareas programadas          |

Como no podía ser de otra forma (si no el mundo sería muy fácil) cada uno de estos métodos tiene sus propias ventajas y desventajas. En este artículo, exploraremos las diferentes opciones disponibles

### Usar rc.local

Para configurar el archivo `rc.local` y ejecutar una aplicación al arranque, comenzamos abriendo el archivo `/etc/rc.local` en un editor de texto con permisos de superusuario utilizando el siguiente comando:

```bash
sudo nano /etc/rc.local
```

Dentro del archivo, antes de la línea `exit 0`, añadimos el comando para iniciar nuestra aplicación o script. Por ejemplo, para ejecutar un script Python, añadimos:

```bash
/usr/bin/python3 /home/pi/miscripts/miscript.py &
```

Es importante añadir el `&` al final del comando para asegurar que el proceso se ejecute en segundo plano. Después de añadir el comando, guardamos el archivo y cerramos el editor usando `Ctrl+X`, luego `Y`, y presionamos `Enter` Finalmente, reiniciamos nuestra Raspberry Pi para verificar que el comando se ejecuta correctamente utilizando el comando:

```bash
sudo reboot
```

### Usar systemd

`systemd` es el sistema de inicio y gestión de servicios utilizado en Raspberry Pi OS. Proporciona un método más moderno y flexible para ejecutar aplicaciones al arranque. Para configurar un servicio con `systemd`, comenzamos creando un nuevo archivo de servicio en `/etc/systemd/system/`. Por ejemplo, para un servicio llamado `mi_aplicacion`, utilizamos el siguiente comando:

```bash
sudo nano /etc/systemd/system/mi_aplicacion.service
```

Dentro del archivo, introducimos la siguiente configuración:

```bash
[Unit]
Description=Mi Aplicación

[Service]
ExecStart=/usr/bin/python3 /home/pi/miscripts/miscript.py
Restart=always
User=pi

[Install]
WantedBy=multi-user.target
```

- `ExecStart`: Ruta al ejecutable o script.
- `Restart`: Configuración para reiniciar el servicio si falla.
- `User`: Usuario que ejecutará el servicio.

Después de añadir la configuración, guardamos el archivo y cerramos el editor. Para que `systemd` reconozca el nuevo servicio, recargamos la configuración con el siguiente comando:

```bash
sudo systemctl daemon-reload
```

Luego, iniciamos el servicio y lo habilitamos para que se inicie al arranque:

```bash
sudo systemctl start mi_aplicacion
sudo systemctl enable mi_aplicacion
```

Finalmente, comprobamos el estado del servicio para asegurarnos de que está funcionando correctamente:

```bash
sudo systemctl status mi_aplicacion
```

### Agregar el script al directorio autostart

Este método es útil para aplicaciones gráficas y scripts que deben iniciarse en el entorno de escritorio. Para configurar el autostart, comenzamos creando un archivo de entrada en el directorio `~/.config/autostart/`. Por ejemplo, para una aplicación llamada `mi_aplicacion`, utilizamos los siguientes comandos:

```bash
mkdir -p ~/.config/autostart
nano ~/.config/autostart/mi_aplicacion.desktop
```

Dentro del archivo, introducimos la siguiente configuración:

```bash
[Desktop Entry]
Type=Application
Exec=/usr/bin/python3 /home/pi/miscripts/miscript.py
Hidden=false
NoDisplay=false
X-GNOME-Autostart-enabled=true
Name=Mi Aplicación
Comment=Inicia mi aplicación al arranque
```

Después de añadir la configuración, guardamos el archivo y cerramos el editor usando `Ctrl+X`, luego `Y`, y presionamos `Enter`. Finalmente, reiniciamos el entorno de escritorio o la Raspberry Pi para aplicar los cambios. Utilizamos el comando:

```bash
sudo reboot
```

### Usar Cron

El comando `cron` permite programar tareas, y con la opción `@reboot`, puedes ejecutar scripts al arranque. Para configurar `cron`, primero abrimos el archivo `crontab` del usuario actual utilizando el siguiente comando:

```bash
crontab -e
```

Dentro del archivo `crontab`, añadimos una línea para ejecutar nuestro script al arranque. Por ejemplo, podemos añadir:

```bash
@reboot /usr/bin/python3 /home/pi/miscripts/miscript.py
```

Después de añadir la entrada, guardamos el archivo y cerramos el editor usando `Ctrl+X`, luego `Y`, y presionamos `Enter`. Finalmente, reiniciamos nuestra Raspberry Pi para verificar que el script se ejecuta correctamente. Utilizamos el comando:

```bash
sudo reboot
```