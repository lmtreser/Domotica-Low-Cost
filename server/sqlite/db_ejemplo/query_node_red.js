let payload;

let insert = "INSERT INTO eventos (ev_tipo_evento, ev_am_id, ev_di_id, ev_valor, ev_descripcion) ";

let values = "VALUES ('Cambio de temperatura', 2, 1, 23.0, 'La temperatura subió a 23.0°C')";

if (msg.topic == "luces") {
    msg.payload = insert + values;
}
else if (msg.topic == "temperatura") {
    msg.payload = insert + values;
}

return msg;
