let payload;

let insert = "INSERT INTO eventos (ev_tipo_evento, ev_am_id, ev_di_id, ev_valor, ev_descripcion) ";

let values = "VALUES ('Cambio de temperatura', 2, 1, 23.0, 'La temperatura subió a 23.0°C')";

if (msg.topic == "luces") {
    msg.topic = insert + values;
}
else if (msg.topic == "temperatura") {
    msg.topic = insert + values;
}

return msg;

---

let query_0 = "INSERT INTO eventos (ev_tipo_evento, ev_am_id, ev_di_id, ev_valor, ev_descripcion) VALUES ('Cambio de temperatura', 2, 1, 23.0, 'La temperatura subió a 23.0°C'), ('Actuador activado', 2, 2, 1, 'El actuador fue activado')";

msg.topic = query_0;
return msg;

---

let query_1 = "SELECT d.di_tipo AS tipo_dispositivo, a.am_nombre AS ambiente, e.ev_timestamp AS hora, e.ev_valor AS valor FROM eventos e JOIN dispositivos d ON e.ev_di_id = d.di_id JOIN ambientes a ON e.ev_am_id = a.am_id";

msg.topic = query_1;
return msg;

---

let query_2 = "SELECT d.di_tipo AS tipo_dispositivo, a.am_nombre AS ambiente, e.ev_timestamp AS hora, e.ev_valor AS valor FROM eventos e JOIN dispositivos d ON e.ev_di_id = d.di_id JOIN ambientes a ON e.ev_am_id = a.am_id WHERE d.di_tipo = 'sensor'";

msg.topic = query_2;
return msg;
