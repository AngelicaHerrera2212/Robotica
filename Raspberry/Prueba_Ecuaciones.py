#!/usr/bin/env python
# -*- coding: utf-8 -*-
# lsusb to check device name
#dmesg | grep "tty" to find port name

# IMPORTACION DE LIBRERIAS
import serial
import time
import Posiciones as P
import Ecuaciones as DO


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
                        
                        # LOOP INTERMINABLE
                        while True:
                           
                            X = float(input("ENTRE POSICION X: "))
                            Y = float(input("ENTRE POSICION Y: "))
                            Z = float(input("ENTRE POSICION Z: "))
                                 
                            GO = BINGO_POSI(X,Y,Z)
                            
                            #Q1 = float(input("ENTRE POSICION Q1: "))
                            #Q2 = float(input("ENTRE POSICION Q2: "))
                            #Q3 = float(input("ENTRE POSICION Q3: "))
                                 
                            #GO = BINGO_GO(Q1,Q2,Q3)
                            break
            break

    # EXCEPCION DEL CTRL C
    except KeyboardInterrupt:                
        print("KeyboardInterrupt has been caught.")


# NAME IGUAL A MAIN
#if __name__ == '__main__':

# INICIO DEL PROGRAMA E INSTRUCCIONES PARA UTILIZAR
print('Running. Press CTRL-C to exit.')

arduino = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout=1)
# ENTRADA AL ARDUINO Y LA COMUNICACION SERIAL CON EL
#with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
time.sleep(5) #wait for serial to open
arduino.flushInput()
    
if arduino.isOpen():
    print("{} connected!".format(arduino.port))           
        
    # PROGRAMA QUE VA A CORRER
    MAIN()

