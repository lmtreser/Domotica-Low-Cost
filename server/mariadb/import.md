# MariaDB Server

## Importar archivos de consultas

Para importar un archivo con consultas SQL, desde la consola interactiva de MariaDB:

```Bash
sudo mariadb
source /ruta/consultas.sql
```

Para importar un archivo con consultas SQL, desde el terminal:

```bash
mariadb -u usuario -p base_de_datos < /ruta/consultas.sql
```
