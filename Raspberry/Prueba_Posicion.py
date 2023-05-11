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

def BINGO_POSI_X2(X0 = 0, Y0 = 0, Z0 = 0, X1 = 0, Y1 = 0, Z1 = 0):

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




def MAIN():   
    try:
            # LOOP INTERMINABLE
        while True:
            
            GO = INICIO()
            if (GO == "READY"):
                
                GO = CALL_1()
                if (GO == "FASE_1"):
                    
                    GO = CALL_4()
                    if (GO == "FASE_4"):
                        
                        # LOOP INTERMINABLE
                        while True:
                            
                            '''                         
                            X0 = float(input("ENTRE POSICION X: "))
                            Y0 = float(input("ENTRE POSICION Y: "))
                            Z0 = float(input("ENTRE POSICION Z: "))
                            X1 = float(input("ENTRE POSICION X1: "))
                            Y1 = float(input("ENTRE POSICION Y1: "))
                            Z1 = float(input("ENTRE POSICION Z1: "))
                            '''
                            X0 = P.PZ[0][0]
                            Y0 = P.PZ[0][1]
                            Z0 = P.PZ[0][2]
                            X1 = P.PT[0][0]
                            Y1 = P.PT[0][1]
                            Z1 = P.PT[0][2]

                            GO = BINGO_POSI_X2(X0,Y0,Z0,X1,Y1,Z1)
                                
                            if (GO == "PIEZA PUESTA"):
                                print("READY TO GO AGAIN")
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

