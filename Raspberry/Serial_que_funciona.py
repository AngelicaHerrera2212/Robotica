#!/usr/bin/env python
# -*- coding: utf-8 -*-
# lsusb to check device name
#dmesg | grep "tty" to find port name

# IMPORTACION DE LIBRERIAS
import serial
import time
import BINGOBOT_V1 as BOT

# NAME IGUAL A MAIN
if __name__ == '__main__':
    
    # INICIO DEL PROGRAMA E INSTRUCCIONES PARA UTILIZAR
    print('Running. Press CTRL-C to exit.')
    
    # ENTRADA AL ARDUINO Y LA COMUNICACION SERIAL CON EL
    with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
        time.sleep(0.1) #wait for serial to open
        if arduino.isOpen():
            print("{} connected!".format(arduino.port))
            
            # PROGRAMA QUE VA A CORRER 
            try:

                # LOOP INTERMINABLE
                while True:
                    
                    # ESPERAR UN COMANDO DESDE EL KEYBOARD
                    cmd=input("Enter command : ")
                    #cmd = Ecuaciones.SEND
                    
                    # ENVIAR AL ARDUINO
                    arduino.write(cmd.encode())
                    
                    time.sleep(0.1) #wait for arduino to answer
                    while arduino.inWaiting()==0: pass # ESPERAR RESPUESTA DEL ARDUINO
                    if  arduino.inWaiting()>0: # SI LLEGA ALGO DEL ARDUINO
                        
                        result = "NOT READY"
                        
                        while  result != "READY" and result != "FASE_1" and result != "FASE_2" :
                            answer=arduino.readline() # LO LEE
                        
                            #print(answer) # IMPRIMIR EL ASUNTO
                            #print(type(answer)) #TYPO DE DATO DE LA ENTRADA                        
                        
                            result = answer.decode() #CONVERTIR EN STR
                            #print(type(result)) #TYPO DE DATO CON LA CADENA
                        
                            arduino.flushInput() #remove data after reading FROM BUFFER
                        
                            print("ARDUINO DICE:")
                            print(result)			 #IMPRIMIENDO LA STR
            
                        
            # EXCEPCION DEL CTRL C
            except KeyboardInterrupt:                
                print("KeyboardInterrupt has been caught.")
