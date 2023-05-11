import math
import Ecuaciones as ANG

def CIRCLE():

    Y = 23.5
    R = 4.25
    Z0 = 13.25
    X0 = -2

    #17 > Z > 10
    
    print("UP")

    Z = 9
    while (Z <= 17.5):

        X = round((math.sqrt(pow(R,2) - pow((Z - Z0),2)) + X0),2)
        print("X: ",-X,"Y: ", Y, "Z: ", Z)       
        
        Z += 0.5
        
         #print(ANG.CALCULO(X,Y,Z))
    
    print("DOWN")

    X0 = 0
    Z = 17
    while (Z >= 9):
        
        X = round((math.sqrt(pow(R,2) - pow((Z - Z0),2)) - X0),2)

        print("X: ",X,"Y: ", Y, "Z: ", Z)       
        
        Z -= 0.5
        #print(ANG.CALCULO(X,Y,Z))

CIRCLE()