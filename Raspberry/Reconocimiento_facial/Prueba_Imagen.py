import cv2
import pytesseract
from pytesseract import Output

cap = cv2.VideoCapture(0) # INICIA LA CAMARA
cap.set(cv2.CAP_PROP_BUFFERSIZE, 1) # TAMAÑO DE BUFFER DE UN CAUDRO

while True:
    # Captura de cuadro por cuadro
    ret, cuadro = cap.read() #LEE EL CUADRO ACTUAL
    d = pytesseract.image_to_data(cuadro, lang='spa', output_type=Output.DICT) #INFORMACION DE LO LEIDO
    cant_cajas = len(d['text']) # CUANTAS LETRAS HAY
    for i in range(cant_cajas): # PARA CADA CAJA
    # Procesar solo con nivel de confianza mayor a 60 %
        if int(d['conf'][i]) > 60:
            (text, x, y, w, h) = (d['text'][i], d['left'][i], d['top'][i], d['width'][i], d['height'][i])
            # no mostrar texto vacio
            if text and text.strip() != "": #ASEGURAR QUE EL TEXTO NO ESTE VACIO
                cuadro = cv2.rectangle(cuadro, (x, y), (x + w, y + h), (0, 255, 0), 2)
                cuadro = cv2.putText(cuadro, text, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 0, 255), 3)
                
    # Abre ventana y muestra resultado
    cv2.imshow('cuadro', cuadro)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
 
cap.release()
cv2.destroyAllWindows() 