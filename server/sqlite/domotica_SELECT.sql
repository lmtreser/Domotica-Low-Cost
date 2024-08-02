-- Retorna todos los eventos y muestra dispositivo, ambiente, hora y valor
SELECT
    d.di_tipo AS tipo_dispositivo,
    a.am_nombre AS ambiente,
    e.ev_timestamp AS hora,
    e.ev_valor AS valor
FROM
    eventos e
JOIN
    dispositivos d ON e.ev_di_id = d.di_id
JOIN
    ambientes a ON e.ev_am_id = a.am_id;

-- Retorna todos los eventos de sensores y muestra dispositivo, ambiente, hora y valor
SELECT
    d.di_tipo AS tipo_dispositivo,
    a.am_nombre AS ambiente,
    e.ev_timestamp AS hora,
    e.ev_valor AS valor
FROM
    eventos e
JOIN
    dispositivos d ON e.ev_di_id = d.di_id
JOIN
    ambientes a ON e.ev_am_id = a.am_id
WHERE
    d.di_tipo = 'sensor';
