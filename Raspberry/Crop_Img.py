import cv2
import numpy as np
import pytesseract
import Tablas_position as SQ



def CUT_IMAGE():
    tablas = cv2.imread('/home/gene/Desktop/BACKUP_RASPI/Raspberry/opencv_foto_tabla_0.jpg')
    cv2.imshow("Original", tablas)
    
    cortada = img[SQ.TB[0][0]: [0][1], [0][2]: [0][3]]
    cv2.imshow("CUT",cortada)



img = cv2.imread('/home/gene/Desktop/BACKUP RASPI/Raspberry/opencv_foto_tabla_0.jpg')
cv2.imshow("Original", img)



linea, colum, _ = img.shape

print("LINEAS: ", linea)
print("COLUMNAS: ", colum)

cortada = img[210: 290, 190: 255]
cv2.imshow("CUT",cortada)

image_grayscale = cv2.cvtColor(cortada, cv2.COLOR_BGR2GRAY)
cv2.imshow('IN GREY',image_grayscale)

#thresh = 175

#image_binary = cv2.threshold(image_grayscale, thresh, 255, cv2.THRESH_BINARY)[1]
#cv2.imshow('BINARY',image_binary)


# cv2.imwrite('BINARY_opencv_foto_0.jpg',image_binary)
# invertida = np.invert(cortada)
# cv2.imshow("INV",invertida)

text = pytesseract.image_to_string(image_grayscale,lang='spa',config='--psm 3')
print(text)

#num = ""

#for i in text:
#    if i.isdigit():
#        num += i


#num_int = int(num)
#print(num_int)
#print(type(num_int))


# cv2.imwrite("INV.jpg", invertida)

cv2.waitKey(0)