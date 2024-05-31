# Ejemplo para publicar en topic MQTT

import paho.mqtt.client as mqtt

broker = "broker.hivemq.com"
puerto = 1883
topic_str = "lmtreser/str"
topic_int = "lmtreser/int"
topic_float = "lmtreser/float"

mensaje_str = "¡Hola Mundo!"
mensaje_int = 123
mensaje_float = 3.1416

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.connect(broker, puerto)

client.publish(topic_str, mensaje_str)
client.publish(topic_int, mensaje_int)
client.publish(topic_float, mensaje_float)

print("Desconectando...")
client.disconnect()