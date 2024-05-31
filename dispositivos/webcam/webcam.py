import cv2

# Abrir la cámara (0 es el ID de la cámara predeterminada)
cap = cv2.VideoCapture('/dev/video2')

if not cap.isOpened():
    print("Error: No se puede abrir la cámara")
    exit()

# Capturar un frame
ret, frame = cap.read()

if ret:
    # Guardar la imagen capturada en el disco
    cv2.imwrite('captura.jpg', frame)
    print("Foto guardada como captura.jpg")
else:
    print("Error: No se pudo capturar la imagen")

# Liberar el recurso de captura
cap.release()