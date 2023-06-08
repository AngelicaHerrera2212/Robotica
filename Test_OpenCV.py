import cv2
import numpy as np
import matplotlib.pyplot as plt
import pytesseract

kernel = np.ones((5,5),np.uint8)

im_name = "Table_Pics\Table_1.jpeg"
Image = cv2.imread(im_name)
cv2.imshow("Original",Image)

image_grayscale = cv2.cvtColor(Image, cv2.COLOR_BGR2GRAY)
cv2.imshow('IN GREY',image_grayscale)

# Imagen Blured
imageBlur = cv2.GaussianBlur(image_grayscale, (5,5), 1)
cv2.imshow('BLUR', imageBlur)

# Imagen dilatada
image_Dilat = cv2.dilate(imageBlur, kernel, iterations = 1)
cv2.imshow('Imagen Dilatada', image_Dilat)
cv2.imwrite("/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_Dilatada.jpg", image_Dilat)

# Imagen Erode
image_Erode = cv2.erode(image_Dilat, kernel, iterations = 1)
cv2.imshow('Imagen Eroded', image_Erode)

# BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
thresh = 80
image_binary = cv2.threshold(image_Erode, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow('BINARY',image_binary)

# CONTORNOS
CONT, JERAR = cv2.findContours(image_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
print(CONT)
print(JERAR)

for i in range(len(CONT)):
    CNT = CONT[i]
    area = cv2.contourArea(CNT)
    print("A: ", area)
    #cv2.drawContours(image, CONT, i, (255,0,0), 2)
    #cv2.imshow('IMAGEN CONTORNOS', image)    
    #cv2.waitKey(0)

    if (area > 100000.0 and area < 200000.0 ):
        cv2.drawContours(Image, CONT, i, (255,0,0), 2)
        cv2.imshow('IMAGEN CONTORNOS', Image)
        #print("ID: ", i)
        #print("A: ", area) 
        ID = i 
        #A = area
        #cv2.waitKey(0)

# waits for user to press any key
# (this is necessary to avoid Python kernel form crashing)
cv2.waitKey(0)
  
# closing all open windows
cv2.destroyAllWindows()