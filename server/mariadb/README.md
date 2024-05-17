# MariaDB Server

- `actuadores.sql` Consultas SQL para trabajar con actuadores
- `consultas.sql` Consultas SQL para crear la base de datos "domótica"
- `domotica.sql` Consultas SQL para trabajar con la base de datos "domótica"
- `Tablas.ods` Planificación de las tablas de la base de datos "domótica"

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
