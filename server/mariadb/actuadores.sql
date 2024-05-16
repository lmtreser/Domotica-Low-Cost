--  BASE DE DATOS 'DOMOTICA'
--
--  Tabla y procedimiento para trabajar con actuadores
--
--  Para importar un archivo con consultas SQL:
--  Desde la consola interactiva: source /ruta/consultas.sql
--  Desde el terminal: mariadb -u usuario -p base_de_datos < /ruta/consultas.sql
--
--
--  Cuando se recibe un comando para cambiar el estado del actuador, inserta un
--  nuevo registro en la tabla de eventos con el estado del actuador, la fecha y
--  hora actuales y procesado establecido en 0 (indicando que aún no ha sido
--  procesado por el actuador).
--
--  El actuador, al consultar la base de datos, buscará el registro más antiguo
--  que aún no haya sido procesado (es decir, procesado igual a 0). Esto se puede
--  hacer utilizando una consulta SQL que seleccione el registro más antiguo con
--  procesado igual a 0, ordenado por la fecha y hora en orden ascendente.
--
--  Una vez que el actuador haya procesado el evento, actualiza el campo procesado
--  a 1 para indicar que ya ha sido procesado.

-- -------------------------------------
-- CREAR LA TABLA EVENTOS
-- -------------------------------------

CREATE TABLE eventos (
    id INT PRIMARY KEY AUTO_INCREMENT,
    estado_actuador INT,
    fecha_hora TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    procesado BOOLEAN DEFAULT 0
);

-- -------------------------------------
-- CONSULTAR POR EVENTOS SIN PROCESAR
-- -------------------------------------

SELECT * FROM eventos WHERE procesado = 0 ORDER BY fecha_hora ASC LIMIT 1;

--  La consulta SQL ORDER BY fecha_hora ASC LIMIT 1 tiene dos partes principales:
--
--  ORDER BY fecha_hora ASC: Esto ordena los resultados de la consulta en función
--  del campo fecha_hora en orden ascendente (ASC), es decir, desde los registros
--  más antiguos hasta los más recientes. Esto garantiza que obtendrás el evento
--  más antiguo primero.
--
--  LIMIT 1: Esto limita el número de filas devueltas por la consulta a solo una.
--  En este caso, devuelve solo la fila superior, es decir, el evento más antiguo
--  que aún no ha sido procesado por el actuador.

-- -------------------------------------
-- PROCESAR EVENTOS
-- -------------------------------------

--  La actualización del campo procesado debe ser realizada por el actuador después
--  de procesar el evento. El actuador consulta la base de datos para obtener el
--  siguiente evento sin procesar, procesa el evento según sea necesario.
--
--  Después de procesar el evento, actualiza el campo procesado en la fila
--  correspondiente de la tabla de eventos para indicar que el evento ha sido
--  procesado.

-- Consulta para obtener el próximo evento sin procesar
SELECT * FROM Eventos WHERE Procesado = 0 ORDER BY fecha_hora ASC LIMIT 1")

-- Actualizar el campo "Procesado" en la fila correspondiente
UPDATE Eventos SET Procesado = 1 WHERE id = %s", (id_evento,))
