import serial
import time

Ard = serial.Serial('/dev/ttyACM0', baudrate = 9600)
Ard.flushInput()

while True:
    
    try:
        mens = "a"
        send = mens.encode('UTF-8')
        Ard.write(send)
        time.sleep(1)
        
        #Ard.write([141])
        #time.sleep(1)
        
        #Ard.write([142])
        #time.sleep(1)
        
        lineB = Ard.readline()
        line = lineB.decode('UTF-8').strip()
        print(line)
        
        mens = "b"
        send = mens.encode('UTF-8')
        Ard.write(send)
        time.sleep(1)
         
        
        #Ard.write([141])
        #time.sleep(1)
        
        #Ard.write([142])
        #time.sleep(1)
        
        lineB = Ard.readline()
        line = lineB.decode('UTF-8').strip()
        print(line)
        
        
    
    except KeyboardInterrupt:
        break