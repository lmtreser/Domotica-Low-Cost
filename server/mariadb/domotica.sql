-- BASE DE DATOS 'DOMOTICA'
--
--  Base de datos para almacenar datos de sensores y actuadores. Se pueden establecer
--  las siguientes relaciones:
--
--  * Un lugar puede tener varios dispositivos, por lo que la relación entre LUGAR
--    y DISPOSITIVOS es de uno a muchos.
--
--  * Cada dispositivo tiene un único proveedor, por lo que la relación entre
--    DISPOSITIVOS y PROVEEDORES es de uno a uno.
--
--  * Varios eventos pueden estar asociados a un dispositivo, lo que significa que la
--    relación entre DISPOSITIVOS y EVENTOS es de uno a muchos.
--
--  Para importar un archivo con consultas SQL:
--  Desde la consola interactiva: source /ruta/consultas.sql
--  Desde el terminal: mariadb -u usuario -p base_de_datos < /ruta/consultas.sql
--

-- -------------------------------------
-- TAREAS ADMINISTRATIVAS
-- -------------------------------------

-- Crear la base de datos
CREATE DATABASE IF NOT EXISTS domotica;

-- Crear un usuario
-- CREATE USER 'nombre'@'host' IDENTIFIED BY 'password';
CREATE USER 'adminrpi' IDENTIFIED BY 'adminrpi';
CREATE USER 'clientread' IDENTIFIED BY 'clientread';
CREATE USER 'clientwrite' IDENTIFIED BY 'clientwrite';

-- Otorgar privilegios a un usuario
-- GRANT ALL PRIVILEGES ON database.* TO 'usuario'@'host';
GRANT ALL PRIVILEGES ON domotica.* TO 'adminrpi';
GRANT SELECT ON domotica.* TO 'clientread';
GRANT INSERT ON domotica.* TO 'clientwrite';

-- Iniciar sesión con el usuario, y luego elegir la base de datos
USE domotica;

-- -------------------------------------
-- CREACIÓN Y MODIFICACIÓN DE TABLAS
-- -------------------------------------

-- Creación de la tabla LUGAR
CREATE TABLE Lugar (
    ID INT AUTO_INCREMENT PRIMARY KEY,
    Nombre VARCHAR(20)
);

-- Creación de la tabla PROVEEDORES
CREATE TABLE Proveedores (
    ID INT AUTO_INCREMENT PRIMARY KEY,
    Proveedor VARCHAR(20),
    Direccion VARCHAR(60),
    Ciudad VARCHAR(30)
);

-- Creación de la tabla DISPOSITIVOS
CREATE TABLE Dispositivos (
    ID INT AUTO_INCREMENT PRIMARY KEY,
    ID_Lugar INT,
    ID_Proveedor INT,
    Marca VARCHAR(20),
    Modelo VARCHAR(30),
    S_N VARCHAR(30),
    Descripcion VARCHAR(50),
    Fecha_Compra DATE,
    Fecha_Instalacion DATE,
    FOREIGN KEY (ID_Lugar) REFERENCES Lugar(ID),
    FOREIGN KEY (ID_Proveedor) REFERENCES Proveedores(ID)
);

-- Creación de la tabla EVENTOS
CREATE TABLE Eventos (
    ID INT AUTO_INCREMENT PRIMARY KEY,
    ID_Dispositivo INT,
    Tipo VARCHAR(30),
    Valor INT,
    Fecha_Hora DATETIME,
    FOREIGN KEY (ID_Dispositivo) REFERENCES Dispositivos(ID)
);

-- Modificar una tabla
ALTER TABLE Lugar CHANGE Nombre Ambiente VARCHAR(20);

-- -------------------------------------
-- INSERTAR DATOS EN LAS TABLAS
-- -------------------------------------

-- Inserción de datos en la tabla LUGAR
INSERT INTO Lugar (Ambiente)
VALUES
    ('Cocina'),
    ('Living'),
    ('Baño'
);

-- Inserción de datos en la tabla PROVEEDORES
INSERT INTO Proveedores (Proveedor, Direccion, Ciudad)
VALUES
    ('Ciardi Hnos.', 'Av. Luro 7146', 'Mar del Plata'),
    ('Casa Blanco', 'Av. Independencia 1964', 'Mar del Plata'),
    ('Electro Stock', 'La Rioja 2002', 'Mar del Plata'
);

-- Inserción de datos en la tabla DISPOSITIVOS
INSERT INTO Dispositivos (
    ID_Lugar,
    ID_Proveedor,
    Marca,
    Modelo,
    S_N,
    Descripcion,
    Fecha_Compra,
    Fecha_Instalacion)
VALUES
    (1, 1, 'Finder', '18.5K.9.030.0001', 'ABC1023', 'Detectores de movimiento y presencia','2024-04-25', '2024-04-26'),
    (1, 1, 'Finder', '15.2K.8.230.0400', 'ABC7789', 'Dimmer universal de 2 canales KNX',
    '2024-04-25', '2024-04-26'),
    (1, 3, 'Finder', '19.6K.9.030.4300', 'ABC1122', 'Actuador 6 canales KNX',
    '2024-04-25', '2024-04-26'
);

-- Inserción de datos en la tabla EVENTOS
INSERT INTO Eventos (ID_Dispositivo, Tipo, Valor, Fecha_Hora)
VALUES
    (1, 'Falla', 0, '2024-04-25 10:15:00'),
    (1, 'Activación', 1, '2024-04-25 11:30:00'),
    (2, 'Alerta', 1, '2024-04-26 09:45:00'
);

-- -------------------------------------
-- MODIFICAR REGISTROS
-- -------------------------------------

-- Modificar registros
UPDATE Dispositivos
SET Fecha_Compra = '2024-04-25'
WHERE ID = 1;

UPDATE Dispositivos
SET Fecha_Instalacion = '2024-04-26'
WHERE ID = 1;

-- -------------------------------------
-- CONSULTA DE DATOS
-- -------------------------------------

-- Consultas generales sobre cualquier tabla
SELECT * FROM Eventos;

-- Consultar datos desde dos tablas relacionadas
SELECT Eventos.Tipo, Eventos.Valor, Eventos.Fecha_Hora, Dispositivos.Marca, Dispositivos.S_N
FROM Eventos
JOIN Dispositivos ON Eventos.ID_Dispositivo = Dispositivos.ID;

-- Consultar datos desde tres tablas relacionadas
SELECT Eventos.Tipo, Eventos.Fecha_Hora, Eventos.Valor, Dispositivos.Marca, Dispositivos.S_N, Lugar.Ambiente
FROM Eventos
JOIN Dispositivos ON Eventos.ID_Dispositivo = Dispositivos.ID
JOIN Lugar ON Lugar.ID = Dispositivos.ID_Lugar;
