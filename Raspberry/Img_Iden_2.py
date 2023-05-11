#!/usr/bin/env python
# -*- coding: utf-8 -*-
# lsusb to check device name
#dmesg | grep "tty" to find port name

import cv2
import numpy as np
import matplotlib.pyplot as plt
import pytesseract
import Table_Mtx as MT


def IDENTIFY(TAB = 0):
    
    if TAB > 2:
        if TAB == 3:
            # TABLA 1
            kernel = np.ones((5,5),np.uint8)
            #print(kernel)

            im_name = "/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_{}.jpg".format(TAB)

            # Imagen Original
            image = cv2.imread(im_name)
            #cv2.imshow('RGB', image)

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

                if (area > 70000.0):
                    cv2.drawContours(image, CONT, i, (255,0,0), 2)
                    #cv2.imshow('IMAGEN CONTORNOS', image)
                    #print("ID: ", i)
                    #print("A: ", area) 
                    ID = i
                    #A = area
                    #cv2.waitKey(0)



            # ENCONTRAR LOS PUTOS LIMITE DEL CONTORNO
            CNT = CONT[ID]

            # TOMANDO EN CUENTA LA INCLINACION
            rect = cv2.minAreaRect(CNT)
            box = cv2.boxPoints(rect)
            box = np.int0(box)

            cv2.drawContours(image, [box], 0, (0,0,255), 2)
            #cv2.imshow('IMAGEN CUADRADO VOLTEADO', image)
            #print(box)


            PT1 = np.float32(box)
            PT2 = np.float32([[0,0],[400,0],[400,400],[0,400]])

            M = cv2.getPerspectiveTransform(PT1,PT2)
            DST = cv2.warpPerspective(image, M, (400,400))
            #cv2.imshow('NEW',DST)


            thresh = 20 
            #PUEDE SER 110 O 90
            BINARY = cv2.threshold(DST, thresh, 255, cv2.THRESH_BINARY)[1]
            #cv2.imshow('BINARY 2',BINARY)

            #cv2.waitKey(0)

            text = pytesseract.image_to_string(BINARY,lang='spa',config='--psm 6')
            print(text)

            TABLA_NUMB = [["" for i in range(5)] for j in range(5)]
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
                    TABLA_NUMB[j][k] = var
                    var = ""
                    k += 1
                    
                    if k > 4:
                        k = 0
                        j += 1

            TAB_ID = [TABLA_NUMB[0][0], TABLA_NUMB[0][1],TABLA_NUMB[0][2]]

            
            #cv2.waitKey(0)
            cv2.destroyAllWindows()
            
            return TAB_ID
    
        elif TAB == 4:

            # TABLA 2
            kernel = np.ones((5,5),np.uint8)
            #print(kernel)

            im_name = "/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_{}.jpg".format(TAB)

            # Imagen Original
            image = cv2.imread(im_name)
            #cv2.imshow('RGB', image)

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
            # BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
            thresh = 90
            image_binary = cv2.threshold(image_Erode, thresh, 255, cv2.THRESH_BINARY)[1]
            #cv2.imshow('BINARY 2',image_binary)

            # Imagen Canny
            image_Canny = cv2.Canny(image_binary, 100, 100)
            #cv2.imshow('CANNY 1', image_Canny)


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


            ## TABLA 2

                if (area > 65000.0  and   area < 100000):
                    #cv2.drawContours(image, CONT, i, (255,0,0), 2)
                    #cv2.imshow('IMAGEN CONTORNOS', image)
                    #print("ID: ", i)
                    #print("A: ", area) 
                    ID = i
                    A = area
                    #cv2.waitKey(0)

            # ENCONTRAR LOS PUTOS LIMITE DEL CONTORNO
            CNT = CONT[ID]

            # TOMANDO EN CUENTA LA INCLINACION
            rect = cv2.minAreaRect(CNT)
            box = cv2.boxPoints(rect)
            box = np.int0(box)

            box[0][0] = box[0][0] + 7 
            box[1][0] = box[1][0] - 12 
            box[1][1] = box[1][1] + 3

            cv2.drawContours(image, [box], 0, (0,0,255), 2)
            cv2.imshow('IMAGEN CUADRADO VOLTEADO', image)
            #print(box)


            PT1 = np.float32(box)

            PT2 = np.float32([[0,0],[400,0],[400,400],[0,400]])
            #PT2 = np.float32([[0,400],[0,0],[400,0],[400,400]])

            M = cv2.getPerspectiveTransform(PT1,PT2)
            DST = cv2.warpPerspective(image, M, (400,400))
            #cv2.imshow('NEW',DST)

            #BINARIZACION PARA IDENTIFICACION
            thresh = 75
            #PUEDE SER 110 O 90
            BINARY = cv2.threshold(DST, thresh, 255, cv2.THRESH_BINARY)[1]
            #cv2.imshow('BINARY 2',BINARY)

            text = pytesseract.image_to_string(BINARY,lang='spa',config='--psm 6')
            #print(text)

            TABLA_NUMB = [["" for i in range(5)] for j in range(5)]
            #print(TAB1)

            #cv2.waitKey(0)

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
                    TABLA_NUMB[j][k] = var
                    var = ""
                    k += 1
                    
                    if k > 4:
                        k = 0
                        j += 1

            TAB_ID = [TABLA_NUMB[0][0], TABLA_NUMB[0][1],TABLA_NUMB[0][2]] 
            #print(TAB_ID)

            #cv2.waitKey(0)
            cv2.destroyAllWindows()
            
            return TAB_ID
        
        elif TAB == 5:

            kernel = np.ones((5,5),np.uint8)
            #print(kernel)

            im_name = "/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_{}.jpg".format(TAB)

            # Imagen Original
            image = cv2.imread(im_name)
            #cv2.imshow('RGB', image)

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
            image_Canny = cv2.Canny(image_Erode, 150, 150)
            #cv2.imshow('CANNY 1', image_Canny)

            # BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
            thresh = 127
            image_binary = cv2.threshold(image_Canny, thresh, 255, cv2.THRESH_BINARY)[1]
            #cv2.imshow('BINARY 2',image_binary)

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


            ## UNO

                if (area > 10000.0):
                    cv2.drawContours(image, CONT, i, (255,0,0), 2)
                    cv2.imshow('IMAGEN CONTORNOS', image)
                    #print("ID: ", i)
                    #print("A: ", area) 
                    ID = i
                    A = area
                    #cv2.waitKey(0)

            # ENCONTRAR LOS PUTOS LIMITE DEL CONTORNO
            CNT = CONT[ID]

            # TOMANDO EN CUENTA LA INCLINACION
            rect = cv2.minAreaRect(CNT)
            box = cv2.boxPoints(rect)
            box = np.int0(box)

            for j in range(2):
                box[0][j] = box[0][j] - 100

            for j in range(2):
                box[2][j] = box[2][j] + 100
            
            box[1][0] = box[1][0] + 100
            box[1][1] = box[1][1] - 100
            
            box[3][0] = box[3][0] - 100
            box[3][1] = box[3][1] + 100  

            cv2.drawContours(image, [box], 0, (0,0,255), 2)
            cv2.imshow('IMAGEN CUADRADO VOLTEADO', image)
            print(box)

            PT1 = np.float32(box)
            PT2 = np.float32([[0,0],[200,0],[200,200],[0,200]])

            M = cv2.getPerspectiveTransform(PT1,PT2)
            DST = cv2.warpPerspective(image, M, (200,200))
            #cv2.imshow('NEW',DST)


            # Imagen en escala de grises
            GRAY = cv2.cvtColor(DST, cv2.COLOR_BGR2GRAY)
            #cv2.imshow('IN GREY',GRAY)
            
            
            #BINARIZACION PARA IDENTIFICACION
            thresh = 200
            #PUEDE SER 110 O 90
            BINARY = cv2.threshold(GRAY, thresh, 255, cv2.THRESH_BINARY)[1]
            #cv2.imshow('BINARY 2',BINARY)
            

            text = pytesseract.image_to_string(BINARY,lang='spa',config='--psm 6')
            #print(len(text))

            for i in range(len(text)):
                if(text[i].isdigit() and text[i] != '0'):
                    var += text[i]
                else:
                    var = '0'
            
            return var

    
        else:
            return("NO ES UNA ENTRADA VALIDA")

def WRITE_TABLA(TB_ID):
    TAB = IDENTIFY(TB_ID)

    if (TAB[0] == MT.TB_1[0][0] and TAB[1] == MT.TB_1[0][1] and TAB[2] == MT.TB_1[0][2]):
        COMP_TAB = MT.TB_1
    
    elif (TAB[0] == MT.TB_2[0][0] and TAB[1] == MT.TB_2[0][1] and TAB[2] == MT.TB_2[0][2]):
        COMP_TAB = MT.TB_2
    
    elif (TAB[0] == MT.TB_3[0][0] and TAB[1] == MT.TB_3[0][1] and TAB[2] == MT.TB_3[0][2]):
        COMP_TAB = MT.TB_3
    
    elif (TAB[0] == MT.TB_4[0][0] and TAB[1] == MT.TB_4[0][1] and TAB[2] == MT.TB_4[0][2]):
        COMP_TAB = MT.TB_4
    
    elif (TAB[0] == MT.TB_5[0][0] and TAB[1] == MT.TB_5[0][1] and TAB[2] == MT.TB_5[0][2]):
        COMP_TAB = MT.TB_5
    
    elif (TAB[0] == MT.TB_6[0][0] and TAB[1] == MT.TB_6[0][1] and TAB[2] == MT.TB_6[0][2]):
        COMP_TAB = MT.TB_6
    
    elif (TAB[0] == MT.TB_7[0][0] and TAB[1] == MT.TB_7[0][1] and TAB[2] == MT.TB_7[0][2]):
        COMP_TAB = MT.TB_7
    
    elif (TAB[0] == MT.TB_8[0][0] and TAB[1] == MT.TB_8[0][1] and TAB[2] == MT.TB_8[0][2]):
        COMP_TAB = MT.TB_8
    
    elif (TAB[0] == MT.TB_9[0][0] and TAB[1] == MT.TB_9[0][1] and TAB[2] == MT.TB_9[0][2]):
        COMP_TAB = MT.TB_9
    
    elif (TAB[0] == MT.TB_10[0][0] and TAB[1] == MT.TB_10[0][1] and TAB[2] == MT.TB_10[0][2]):
        COMP_TAB = MT.TB_10
    
    elif (TAB[0] == MT.TB_11[0][0] and TAB[1] == MT.TB_11[0][1] and TAB[2] == MT.TB_11[0][2]):
        COMP_TAB = MT.TB_11
    
    else:
        COMP_TAB = [['','','','',''],['','','','',''],['','','Y','',''],['','','','',''],['','','','','']]
    
    return COMP_TAB

#print(IDENTIFY(3))
#print(WRITE_TABLA(3))