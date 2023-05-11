#!/usr/bin/env python
# -*- coding: utf-8 -*-
# lsusb to check device name
#dmesg | grep "tty" to find port name

# IMPORTACION DE LIBRERIAS
import serial
import time
import math
import Posiciones as P
import Ecuaciones as DO
import Img_Iden_2 as TB
import cv2
import Screen as F
import Table_Mtx as MTX
import Existe
import WIN_OR_NOT as CHECK


def INICIO():
    
    print("INICIO") 
    
    cmd = "<START>"

    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
        
    result = "NOT READY"

    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                           
        while  result != "READY":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_1():

    print("CALL 1")

    cmd = "<LISTO>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "FASE"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "FASE_1":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_2():

    print("CALL 2")

    cmd = "<FASE_2>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
        
    result = "FASE"
    
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO
                        
        while  result != "FASE_2":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_3():

    print("CALL 3")

    cmd = "<FASE_3>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
        
    result = "FASE"
    
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO
                        
        while  result != "FASE_3":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result

def CALL_4():

    print("CALL 4")

    cmd = "<FASE_4>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
        
    result = "FASE"
    
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO
                        
        while  result != "FASE_4":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def BINGO_GO(A1 = 0, A2 = 0, A3 = 0):

    print("GO")

    # CALCULAR ANGULOS
    MESAGE = "<"+str(A1)+","+str(A2)+","+str(A3)+">"
    print(MESAGE);
    
    # ENVIAR AL ARDUINO
    arduino.write(MESAGE.encode())
        
    result = "NOT POSITION"
        
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO

        while (result != "POSICION ALCANZADA") and (result != "NO SON ANGULOS VALIDOS"):

            time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
                                        
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result                     



def BINGO_TOM(X = 0, Y = 0, Z = 0):

    print("TOMBOLA")

    # CALCULAR ANGULOS
    ANGULO = DO.CALCULO(X, Y, Z)
    print(ANGULO);
    
    # ENVIAR AL ARDUINO
    arduino.write(ANGULO.encode())
        
    result = "NOT TOMBOLA"
        
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO

        while (result != "TOMBOLA DID") and (result != "NO SON ANGULOS VALIDOS"):

            time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
                                        
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result                     


def BINGO_POSI(X = 0, Y = 0, Z = 0):

    print("POSI")

    # CALCULAR ANGULOS
    ANGULO = DO.CALCULO(X, Y, Z)
    print(ANGULO);
    
    # ENVIAR AL ARDUINO
    arduino.write(ANGULO.encode())
        
    result = "NOT POSITION"
        
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO

        while (result != "POSICION ALCANZADA") and (result != "NO SON ANGULOS VALIDOS"):

            time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
                                        
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result

def BINGO_POSI_X2(X0 = 0, Y0 = 0, Z0 = 0, X1 = 0, Y1 = 0, Z1 = 0):

    GO = CALL_4()
    if (GO == "FASE_4"):

        print("POSI X2")

        # CALCULAR ANGULOS
        ANGULO = DO.CALCULO_X2(X0, Y0, Z0, X1, Y1, Z1)
        print(ANGULO);
        
        # ENVIAR AL ARDUINO
        arduino.write(ANGULO.encode())
            
        result = "NOT POSITION"
            
        while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
        if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO

            while (result != "PIEZA PUESTA") and (result != "NO SON ANGULOS VALIDOS"):

                time.sleep(0.1) #wait for arduino to answer
                answer=arduino.readline() # LO LEE                        
                result = answer.decode() #CONVERTIR EN STR
                arduino.flushInput() #remove data after reading FROM BUFFER
                                            
                #IMPRIME LO QUE RECIBIO
                print("ARDUINO DICE:")
                print(result) #IMPRIMIENDO LA STR
                
        return result


def FUN_1(TABLA = 0):
    
    if(TABLA == 1):
        # FUNCION 1
        GO = BINGO_POSI(P.PC[0][0],P.PC[0][1],P.PC[0][2])
        if (GO == "POSICION ALCANZADA"):
            ACT = "TAKE"
            while (ACT != "Screenshot Taken"):
                time.sleep(2)
                ACT = F.TAKE_PICK(3)
                                
                T = TB.WRITE_TABLA(3)
                #print(T)
                return(T)

    elif(TABLA == 2):
        # TABLA 2
        GO = BINGO_POSI(P.PC[1][0],P.PC[1][1],P.PC[1][2])
        if (GO == "POSICION ALCANZADA"):
            ACT = "TAKE"
            while (ACT != "Screenshot Taken"):
                time.sleep(2)
                ACT = F.TAKE_PICK(4) 
                T = TB.WRITE_TABLA(4)
                #print(T)
                return(T)

    else:
        return([['','','','',''],['','','','',''],['','','Y','',''],['','','','',''],['','','','','']])


def FUN_2():

    GO = CALL_2()
    if (GO == "FASE_2"):

        GO = BINGO_POSI(P.PC[2][0],P.PC[2][1],P.PC[2][2])
        if (GO == "POSICION ALCANZADA"):
            ACT = "TAKE"
            while (ACT != "Screenshot Taken"):
                time.sleep(2)
                ACT = F.TAKE_PICK(5)   
                #IND = TB.IDENTIFY(5)
                
                CALL_LEIDO()

                IND = '74'
            
            return IND

def CALL_OPEN():

    print("CALL OPEN")

    cmd = "<OPEN>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "IS OPEN":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_LOSE():

    print("CALL LOSE")

    cmd = "<LOSE>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "PERDI":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result

def CALL_WIN():

    print("CALL WIN")

    cmd = "<WIN>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "GANE":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_NO_EXISTE():

    print("CALL NO EXISTE")

    cmd = "<NEXIS>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "NO_EXISTE":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result

def CALL_LEIDO():

    print("CALL LEIDO")

    cmd = "<LEIDO>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "LEI":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_UP():

    print("CALL UP")

    cmd = "<GO_UP>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "IT IS LIFT":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result


def CALL_CLOSE():

    print("CALL CLOSE")

    cmd = "<CLOSE>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "IS CLOSE":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result

def CALL_TOM_CLOSE():

    print("CALL TOM CLOSE")

    cmd = "<CLOSE_TOM>"
        
    # ENVIAR AL ARDUINO
    arduino.write(cmd.encode())
   
    result = "ACT"
 
    #time.sleep(0.1) #wait for arduino to answer
    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                        
    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO                       
        while  result != "IS TOM CLOSE":

            #time.sleep(0.1) #wait for arduino to answer
            answer=arduino.readline() # LO LEE                        
            result = answer.decode() #CONVERTIR EN STR
            arduino.flushInput() #remove data after reading FROM BUFFER
            
            #IMPRIME LO QUE RECIBIO
            print("ARDUINO DICE:")
            print(result) #IMPRIMIENDO LA STR
            
    return result

def CIRCLE():

    Y = 23.5
    R = 4.25
    Z0 = 13.25
    X0 = -2

    #17 > Z > 10
    
    Z = 9
    while(Z <= 17.5):
        X = round((math.sqrt(pow(R,2) - pow((Z - Z0),2)) + X0),2)
        
        print("X: ",-X,"Y: ", Y, "Z: ", Z)   
        ACT = BINGO_TOM(-X ,Y ,Z)
        if (ACT == "TOMBOLA DID"):
            Z += 0.25

    #CALL_OPEN()
    
    Z = 17.5
    while(Z >= 17):
        X = round((math.sqrt(pow(R,2) - pow((Z - Z0),2)) - X0),2)
        
        if (Z == 17):
            CALL_OPEN()


        print("X: ",X,"Y: ", Y, "Z: ", Z)   
        ACT = BINGO_TOM(X ,Y ,Z)
        if (ACT == "TOMBOLA DID"):
            Z -= 0.25
    
    BINGO_TOM(6, 23.5, 15.5)
    BINGO_TOM(7, 23.5, 15.5)
    BINGO_TOM(8, 23.5, 15.5)
    BINGO_TOM(9, 23.5, 15.5)
    BINGO_TOM(10, 23.5, 15.5)
    BINGO_TOM(10, 23.5, 14)
    BINGO_TOM(10, 23.5, 13)
    BINGO_TOM(10, 23.5, 10)
    BINGO_TOM(7.5, 23.5, 8.5)
    BINGO_TOM(7.5, 23.5, 7)
    BINGO_TOM(6, 23.5, 5)
    BINGO_TOM(4, 23, 7)
    BINGO_TOM(4, 23, 8)
    BINGO_TOM(-1, 23, 8)

    return "CIRCULO_DONE"

def TOMBOLA():

    GO = CALL_2()
    if (GO == "FASE_2"):

        ACT = CALL_OPEN()
        if(ACT == "IS OPEN"):
                            
            ACT = CALL_UP()
            if (ACT == "IT IS LIFT"):
                                
                ACT = BINGO_POSI(P.TOMB[0] ,P.TOMB[1] ,P.TOMB[2])
                if (ACT == "POSICION ALCANZADA"):
                                        
                    GO = CALL_3()
                    if (GO == "FASE_3"):
                                                
                        ACT = CALL_CLOSE()
                        if(ACT == "IS CLOSE"):
                                                            
                            ACT = CIRCLE()
                            if (ACT == "CIRCULO_DONE"):
                                                                
                                ACT = CALL_OPEN()
                                if(ACT == "IS OPEN"):
                                                                    
                                    ACT = CALL_UP()
                                    if (ACT == "IT IS LIFT"):
                                            
                                        return ("GIRO DE TOMBOLA READY")





def MAIN():

    try:
        
        # LOOP INTERMINABLE
        while True:
            
            GO = INICIO()
            if (GO == "READY"):
                
                GO = CALL_1()
                if (GO == "FASE_1"):
                    
                    GO = CALL_2()
                    if (GO == "FASE_2"):
                        
                        T1 = MTX.TB_7
                        #T2 = MTX.TB_10

                    #T1 = FUN_1(1)
                    #print(T1)
                    
                    #GO = CALL_2()
                    #if (GO == "FASE_2"):

                    #T2 = FUN_1(2)
                    #print(T2)

                        #ACT = TOMBOLA()
                        #if ("GIRO DE TOMBOLA READY"):
                            #print("YES") 
                        
                        #NUM = FUN_2()

                        while(True):

                            NUM = input("INTRODUZCA EL BOLO: ")

                            CHANCE =  Existe.BUSCA(T1, NUM)

                            FILA = 0

                            if (CHANCE[0] == 5):
                                CALL_NO_EXISTE()
                            else:
                                T1[CHANCE[0]][CHANCE[1]] == 'Y'
                                FILA = Existe.P_TAB1(CHANCE)

                                ACT = BINGO_POSI_X2(P.PZ[0][0], P.PZ[0][1], P.PZ[0][2], P.PT[FILA][0], P.PT[FILA][1], P.PT[FILA][2])
                                if (ACT == "PIEZA PUESTA"):

                                    WIN = CHECK.CONFIRM(T1)
                                    if (WIN == True):
                                        ACT = CALL_WIN()
                                    else:
                                        ACT = CALL_LOSE()
                            if(ACT == "GANE"):
                                break
                        '''
                        CHANCE =  Existe.BUSCA(T2, NUM)
                        print(CHANCE)

                        FILA = 0

                        if (CHANCE[0] == 5):
                            CALL_NO_EXISTE()
                        else:
                            T2[CHANCE[0]][CHANCE[1]] == 'Y'
                            FILA = Existe.P_TAB2(CHANCE)
                            print(FILA)
                            

                            ACT = BINGO_POSI_X2(P.PZ[0][0], P.PZ[0][1], P.PZ[0][2], P.PT[FILA][0], P.PT[FILA][1], P.PT[FILA][2])
                            if (ACT == "PIEZA PUESTA"):

                                WIN = CHECK.CONFIRM(T1)
                                if (WIN == True):
                                    ACT = CALL_WIN()
                                else:
                                    ACT = CALL_LOSE()
                        if(ACT == WIN):
                            break
                        '''      
            break


    # EXCEPCION DEL CTRL C
    except KeyboardInterrupt:                
        print("KeyboardInterrupt has been caught.")


# NAME IGUAL A MAIN
#if __name__ == '__main__':

# INICIO D  EL PROGRAMA E INSTRUCCIONES PARA UTILIZAR
print('Running. Press CTRL-C to exit.')
#arduino = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout=1)
# ENTRADA AL ARDUINO Y LA COMUNICACION SERIAL CON EL
with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
#time.sleep(0.1) #wait for serial to open
    arduino.flushInput()
    
    if arduino.isOpen():
        print("{} connected!".format(arduino.port))           
    
        time.sleep(5) #wait for serial to open   
        
        # PROGRAMA QUE VA A CORRER
        MAIN()
        