# CONFIRMACION DE GANANCIA

def CONFIRM(TB):

    WIN = False

    for i in range(5):
        if (TB[i][0] == "Y" and TB[i][1] == "Y" and TB[i][2] == "Y" and TB[i][3] == "Y" and TB[i][4] == "Y"):
            WIN = True
        elif(TB[0][i] == "Y" and TB[1][i] == "Y" and TB[2][i] == "Y" and TB[3][i] == "Y" and TB[4][i] == "Y"):
            WIN = True
        elif(TB[0][0] == "Y" and TB[1][1] == "Y" and TB[2][2] == "Y" and TB[3][3] == "Y" and TB[4][4] == "Y"):
            WIN = True
        elif(TB[0][4] == "Y" and TB[1][3] == "Y" and TB[2][2] == "Y" and TB[3][1] == "Y" and TB[4][0] == "Y"):
            WIN = True

    return WIN

#TB1 = [['Y' for i in range(5)] for j in range(5)]
#print(CONFIRM(TB1))