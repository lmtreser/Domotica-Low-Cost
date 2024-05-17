-- MySQL conexión con Arduino
-- Creado 09/06/2022
-- Modificado 17/05/2024
--

CREATE DATABASE IF NOT EXISTS arduino;
USE arduino;
GRANT ALL PRIVILEGES ON arduino.* TO 'usuario';

CREATE TABLE sensores (
    id INT AUTO_INCREMENT,
    evento TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    idSensor INT,
    humedad FLOAT,
    temperatura FLOAT,
    PRIMARY KEY (id)
    );

INSERT INTO sensores (idSensor, humedad, temperatura) VALUES (1, 90.00, 37.00);
SELECT * FROM sensores;
