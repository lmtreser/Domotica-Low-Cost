# Mediante el siguiente ejemplo, se espera una conexión entrante a través del
# protocolo RFCOMM de Bluetooth, acepta la primera conexión que se realiza y 
# luego recibe 1024 bytes de datos del dispositivo conectado. El dispositivo 
# tiene que estar emparejado previamente antes de poder establecer una conexión.
# 
# Necesita el módulo PyBluez instalado en el sistema.

import bluetooth

server_sock=bluetooth.BluetoothSocket(bluetooth.RFCOMM)

port = 1
server_sock.bind(("",port))
server_sock.listen(1)

client_sock,address = server_sock.accept()
print("Accepted connection from ",address)

data = client_sock.recv(1024)
print("received [%s]" % data)

client_sock.close()
server_sock.close()