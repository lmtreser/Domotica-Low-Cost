-- Insertar ambientes
INSERT INTO ambientes (am_nombre) VALUES ('Habitación');
INSERT INTO ambientes (am_nombre) VALUES ('Cocina');

-- Insertar dispositivos
INSERT INTO dispositivos (di_tipo, di_marca, di_modelo, di_serial, di_descripcion, di_am_id) VALUES
('actuador', 'Sonoff', 'Basic R2', '21-5387', 'Relé interruptor WiFi', 2),
('sensor', 'Analog Devices', 'DS18B20', '19-7487', 'Sensor de temperatura ambiente', 2);

-- Insertar eventos
INSERT INTO eventos (ev_tipo_evento, ev_am_id, ev_di_id, ev_valor, ev_descripcion) VALUES
('Cambio de temperatura', 2, 1, 23.0, 'La temperatura subió a 23.0°C'),
('Actuador activado', 2, 2, 1, 'El actuador fue activado');
