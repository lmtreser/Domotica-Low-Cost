--  BASE DE DATOS 'DOMOTICA'
--
--  Consultas a la Base de datos
--
--  Para importar un archivo con consultas SQL:
--  Desde la consola interactiva: source /ruta/consultas.sql
--  Desde el terminal: mariadb -u usuario -p base_de_datos < /ruta/consultas.sql
--

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
