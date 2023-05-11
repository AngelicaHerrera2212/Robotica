import cv2
import numpy as np
import matplotlib.pyplot as plt
import pytesseract


kernel = np.ones((5,5),np.uint8)
#print(kernel)

# Imagen Original
image = cv2.imread('/home/gene/Desktop/BACKUP RASPI/Raspberry/opencv_foto_tabla_0.jpg')
#cv2.imshow('RGB', image)

# Imagen Resize
image = cv2.resize(image, (400, 300))
cv2.imshow('Resized IMG', image)

# Imagen en escala de grises
image_grayscale = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#cv2.imshow('IN GREY',image_grayscale)


# Imagen Canny
#image_Canny = cv2.Canny(image_grayscale, 50, 50)
#cv2.imshow('CANNY 1', image_Canny)


# Prueba de BINARIZACION

# Imagen Difuminada
imageBlur = cv2.GaussianBlur(image_grayscale, (5,5), 3)
#cv2.imshow('BLUR', imageBlur)


# Imagen dilatada
#image_Dilat = cv2.dilate(imageBlur, kernel, iterations = 2)
#cv2.imshow('Imagen Dilatada', image_Dilat)

image_Dilat_2 = cv2.dilate(image_grayscale, kernel, iterations = 1)
#cv2.imshow('Imagen Dilatada 2', image_Dilat_2)


# Imagen Erode
#image_Erode = cv2.erode(image_Dilat, kernel, iterations = 1)
#cv2.imshow('Imagen Eroded', image_Erode)

image_Erode_2 = cv2.erode(image_Dilat_2, kernel, iterations = 1)
#cv2.imshow('Imagen Eroded 2', image_Erode_2)


# BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
thresh = 127
#image_binary = cv2.threshold(image_grayscale, thresh, 255, cv2.THRESH_BINARY)[1]
#cv2.imshow('BINARY',image_binary)

image_binary_2 = cv2.threshold(image_Erode_2, thresh, 255, cv2.THRESH_BINARY)[1]
#cv2.imshow('BINARY 2',image_binary_2)

# CONTORNOS
CONT, JERAR = cv2.findContours(image_binary_2, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
#print(JERAR)

for i in range(len(CONT)):
    CNT = CONT[i]
    area = cv2.contourArea(CNT)
    #print(area)
    if ((area > 33072.0 - 3500) and (area < 33072.0 + 3500)):
        cv2.drawContours(image, CONT, i, (255,0,0), 2)
        #cv2.imshow('IMAGEN CONTORNOS', image)
        #print(i)
        ID = i
        A = area
        #cv2.waitKey(0)

#El contorno es aproximadamente 33072.0
# ENCONTRAR LOS PUTOS LIMITE DEL CONTORNO
CNT = CONT[ID]

# SIN TOMAR EN CUENTA LA INCLINACION
#x,y,w,h = cv2.boundingRect(CNT)
#cv2.rectangle(image,(x,y),(x+w, y+h), (0,0,255), 2)
#cv2.imshow('IMAGEN CUADRADO', image)
#cv2.waitKey(0)

# TOMANDO EN CUENTA LA INCLINACION
rect = cv2.minAreaRect(CNT)
box = cv2.boxPoints(rect)
box = np.int0(box)
box[2][0] = box[2][0] + 5
box[2][1] = box[2][1] - 6
box[0][0] = box[0][0] + 3
box[3][0] = box[3][0] - 3

cv2.drawContours(image, [box], 0, (0,255,0), 2)
#cv2.imshow('IMAGEN CUADRADO VOLTEADO', image)

#print(x,y,w,h)
#print(box)

#RW,CL,CH = image.shape
#print(RW,CL,CH)

PT1 = np.float32(box)
PT2 = np.float32([[0,0],[400,0],[400,400],[0,400]])

M = cv2.getPerspectiveTransform(PT1,PT2)
DST = cv2.warpPerspective(image, M, (400,400))

#cv2.imshow('NEW',DST)

GRAY = cv2.cvtColor(DST, cv2.COLOR_BGR2GRAY)
#cv2.imshow('NEW GREY',GRAY)

#cv2.drawContours(image_grayscale, CONT, 3, (0,255,0), 2)

'''
# BINARIZACION GAUSIANA
image_binary_3 = cv2.adaptiveThreshold(GRAY, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,11,2)
cv2.imshow('BINARY 3',image_binary_3)
'''


thresh = 125
image_binary_3 = cv2.threshold(GRAY, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow('BINARY 3',image_binary_3)


'''
# CORTADA
CUT1 = image_binary_3[0:85,0:400]
cv2.imshow("CUT1",CUT1)

CUT2 = image_binary_3[85:165,0:400]
cv2.imshow("CUT2",CUT2)

CUT3 = image_binary_3[160:240,0:400]
cv2.imshow("CUT3",CUT3)

CUT4 = image_binary_3[240:320,0:400]
cv2.imshow("CUT4",CUT4)

CUT5 = image_binary_3[320:395,0:400]
cv2.imshow("CUT5",CUT5)


text = pytesseract.image_to_string(CUT1,lang='spa',config='--psm 6')
print(text)

text = pytesseract.image_to_string(CUT2,lang='spa',config='--psm 6')
print(text)

text = pytesseract.image_to_string(CUT3,lang='spa',config='--psm 6')
print(text)

text = pytesseract.image_to_string(CUT4,lang='spa',config='--psm 6')
print(text)

text = pytesseract.image_to_string(CUT5,lang='spa',config='--psm 6')
print(text)

'''

'''
text = pytesseract.image_to_string(image_binary_3,lang='spa',config='--psm 6')
print(text)


TAB1 = [["" for i in range(5)] for j in range(5)]
#print(TAB1)


j = 0;
k = 0;

var = ""

for i in range(len(text)):
    #print(i, text[i])
    if(text[i].isdigit()):
        var += text[i]
    
        if(len(var) == 2 and text[i+1].isdigit()):
            if(((k == 0 and var[0] == "1") or (k == 3 and var[0] == "5")) and (not(text[i+2].isdigit()))):
                var = var[1]
            
            else:
                TAB1[j][k] = var
                var = ""
                k += 1
        
                if k == 5:
                    j += 1
                    k = 0
        print("POS: ",j,k, " , VAR: ", var)
    
    elif((i == len(text)-1) or text[i+1].isdigit()):
        TAB1[j][k] = var
        var = ""
            
        if(j == 2 and k == 1):
            k += 2
        else:
            k += 1
            
        if k == 5:
            j += 1
            k = 0

TAB1[2][2] = "Y"

print(TAB1)
'''

cv2.waitKey(0)
cv2.destroyAllWindows()


'''
# Imagen HSV
image_hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
cv2.imshow('HSV',image_hsv)

# Imagen HLS
image_hls = cv2.cvtColor(image, cv2.COLOR_BGR2HLS)
cv2.imshow('HLS',image_hls)
'''
