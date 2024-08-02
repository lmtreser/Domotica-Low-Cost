# Trabajar con Node-Red y SQLite

En una Raspberry Pi con Node-RED, puedes almacenar el archivo SQLite en cualquier directorio al que Node-RED tenga acceso. Una ubicación común y recomendada es dentro de la carpeta de usuario de Node-RED.

## Ubicación de la carpeta de usuario

La carpeta de usuario de Node-RED suele estar en `~/.node-red` en la Raspberry Pi. Acceder a la carpeta de usuario:

```bash
cd ~/.node-red
```

Crear una carpeta para archivos de dase de datos:

```bash
mkdir databases
```

Mover el archivo SQLite:

```bash
mv /ruta/al/archivo/tu_base_de_datos.sqlite ~/.node-red/databases/
```

Por último, para acceder al archivo desde Node-RED, hay que configurar los nodos proporcionando la ruta correcta al archivo. Por ejemplo `/home/pi/.node-red/databases/tu_base_de_datos.sqlite`.