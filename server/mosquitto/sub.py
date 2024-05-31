# Ejemplo para subscribirse a un topic MQTT

import paho.mqtt.client as mqtt

broker = "broker.hivemq.com"
puerto = 1883
topic_int = "lmtreser/int"

# Callback al conectarse al broker
def on_connect(client, userdata, flags, reason_code, properties):
    print(f"Conectado con el código {reason_code}")
    client.subscribe(topic_int)

# Callback para cuando se recibe un mensaje
def on_message(client, userdata, msg):
    print(f"Mensaje recibido: {msg.payload.decode()} en el tema {msg.topic}")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

# Asignar las funciones de callback al cliente
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker, puerto)
client.loop_forever()