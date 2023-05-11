import cv2
import numpy as np
import matplotlib.pyplot as plt
import pytesseract


# TABLA 1

kernel = np.ones((5,5),np.uint8)
#print(kernel)

# Imagen Original
image = cv2.imread('/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_0.jpg')
cv2.imshow('RGB', image)

# Imagen Resize
#image = cv2.resize(image, (400, 300))
#cv2.imshow('Resized IMG', image)

# Imagen en escala de grises
image_grayscale = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#cv2.imshow('IN GREY',image_grayscale)


# Imagen Blured
imageBlur = cv2.GaussianBlur(image_grayscale, (5,5), 1)
#cv2.imshow('BLUR', imageBlur)


# Imagen dilatada
image_Dilat = cv2.dilate(imageBlur, kernel, iterations = 1)
#cv2.imshow('Imagen Dilatada', image_Dilat)

# Imagen Erode
image_Erode = cv2.erode(image_Dilat, kernel, iterations = 1)
#cv2.imshow('Imagen Eroded', image_Erode)

# Imagen Canny
image_Canny = cv2.Canny(image_Erode, 125, 125)
#cv2.imshow('CANNY 1', image_Canny)


# BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
thresh = 127
image_binary = cv2.threshold(image_Canny, thresh, 255, cv2.THRESH_BINARY)[1]
#cv2.imshow('BINARY 2',image_binary)

'''
# TABLA 2

kernel = np.ones((5,5),np.uint8)
#print(kernel)

# Imagen Original
image = cv2.imread('/home/gene/Desktop/BACKUP RASPI/Raspberry/opencv_tabla_12.jpg')
cv2.imshow('RGB', image)

# Imagen Resize
#image = cv2.resize(image, (400, 300))
#cv2.imshow('Resized IMG', image)

# Imagen en escala de grises
image_grayscale = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow('IN GREY',image_grayscale)


# Imagen Blured
imageBlur = cv2.GaussianBlur(image_grayscale, (5,5), 1)
cv2.imshow('BLUR', imageBlur)


# Imagen dilatada
image_Dilat = cv2.dilate(imageBlur, kernel, iterations = 1)
cv2.imshow('Imagen Dilatada', image_Dilat)

# Imagen Canny
image_Canny = cv2.Canny(image_Dilat, 150, 150)
cv2.imshow('CANNY 1', image_Canny)

# BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
thresh = 127
image_binary = cv2.threshold(image_Canny, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow('BINARY 2',image_binary)

'''
#cv2.waitKey(0)

# CONTORNOS
CONT, JERAR = cv2.findContours(image_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
#print(JERAR)

for i in range(len(CONT)):
    CNT = CONT[i]
    area = cv2.contourArea(CNT)
    #print("A: ", area)
    #cv2.drawContours(image, CONT, i, (255,0,0), 2)
    #cv2.imshow('IMAGEN CONTORNOS', image)    
    #cv2.waitKey(0)    


## TABLA 1

    if (area > 65000.0):
        #cv2.drawContours(image, CONT, i, (255,0,0), 2)
        #cv2.imshow('IMAGEN CONTORNOS', image)
        #print("ID: ", i)
        #print("A: ", area) 
        ID = i
        A = area
        #cv2.waitKey(0)



# ENCONTRAR LOS PUTOS LIMITE DEL CONTORNO
CNT = CONT[ID]

'''
# SIN TOMAR EN CUENTA LA INCLINACION
#x,y,w,h = cv2.boundingRect(CNT)
#cv2.rectangle(image,(x,y),(x+w, y+h), (0,0,255), 2)
#cv2.imshow('IMAGEN CUADRADO', image)
#print(x,y,w,h)

#cv2.waitKey(0)

'''


# TOMANDO EN CUENTA LA INCLINACION
rect = cv2.minAreaRect(CNT)
box = cv2.boxPoints(rect)
box = np.int0(box)

#box[][] = box[][] + 6

cv2.drawContours(image, [box], 0, (0,0,255), 2)
cv2.imshow('IMAGEN CUADRADO VOLTEADO', image)
print(box)


PT1 = np.float32(box)

PT2 = np.float32([[0,0],[400,0],[400,400],[0,400]])
#PT2 = np.float32([[0,400],[0,0],[400,0],[400,400]])

M = cv2.getPerspectiveTransform(PT1,PT2)
DST = cv2.warpPerspective(image, M, (400,400))
cv2.imshow('NEW',DST)

# Imagen Gris
#GRAY = cv2.cvtColor(DST, cv2.COLOR_BGR2GRAY)
#cv2.imshow('NEW GREY',GRAY)

# Imagen Blured
#BLUR = cv2.GaussianBlur(GRAY, (5,5), 1)
#cv2.imshow('BLUR', BLUR)

# Imagen dilatada
#DILAT = cv2.dilate(BLUR, kernel, iterations = 1)
#cv2.imshow('Imagen Dilatada', DILAT)

# Imagen Erode
#ERODE = cv2.erode(DILAT, kernel, iterations = 1)
#cv2.imshow('Imagen Eroded', ERODE)

thresh = 45
#PUEDE SER 110 O 90
BINARY = cv2.threshold(DST, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow('BINARY 2',BINARY)


text = pytesseract.image_to_string(BINARY,lang='spa',config='--psm 6')
print(text)

TAB1 = [["" for i in range(5)] for j in range(5)]
#print(TAB1)

j = 0;
k = 0;

var = ""

for i in range(len(text)):
    
    #print("I: ", i, " = ", text[i])
    if(text[i].isdigit()):
        var += text[i]
    
    elif(text[i] == "Y"):
        var += text[i]
    
    elif((not(text[i].isdigit())) and (var != "")):
        TAB1[j][k] = var
        var = ""
        k += 1
        
        if k > 4:
            k = 0
            j += 1

TAB = [TAB1[0][0], TAB1[0][1], TAB1[0][2]]

#print(TAB)

cv2.waitKey(0)
cv2.destroyAllWindows()
