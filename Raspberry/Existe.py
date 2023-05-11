def BUSCA(T, N):
    
    ID = [5,5]

    print(T)
    print(N)

        #SEE = input("INTRODUZCA VALOR:")

    for i in range(5):
        for j in range(5):
            if (T[i][j] == N):
                ID = [i,j]
    return ID


def P_TAB1(ID):
# TABLA 1 POS

    if(ID[1] == 0):
        if (ID[0] == 0):
            POS = 0
        elif (ID[0] == 1):
            POS = 1
        elif (ID[0] == 2):
            POS = 2
        elif (ID[0] == 3):
            POS = 3
        elif (ID[0] == 4):
            POS = 4

    if(ID[1] == 1):
        if (ID[0] == 0):
            POS = 5
        elif (ID[0] == 1):
            POS = 6
        elif (ID[0] == 2):
            POS = 7
        elif (ID[0] == 3):
            POS = 8
        elif (ID[0] == 4):
            POS = 9

    if(ID[1] == 2):
        if (ID[0] == 0):
            POS = 10
        elif (ID[0] == 1):
            POS = 11
        elif (ID[0] == 2):
            POS = 12
        elif (ID[0] == 3):
            POS = 13
        elif (ID[0] == 4):
            POS = 14

    if(ID[1] == 3):
        if (ID[0] == 0):
            POS = 15
        elif (ID[0] == 1):
            POS = 16
        elif (ID[0] == 2):
            POS = 17
        elif (ID[0] == 3):
            POS = 18
        elif (ID[0] == 4):
            POS = 19

    if(ID[1] == 4):
        if (ID[0] == 0):
            POS = 20
        elif (ID[0] == 1):
            POS = 21
        elif (ID[0] == 2):
            POS = 22
        elif (ID[0] == 3):
            POS = 23
        elif (ID[0] == 4):
            POS = 24

    return (POS)

def P_TAB2(ID):
# TABLA 2 POS
    if(ID[1] == 0):
        if (ID[0] == 0):
            POS = 25
        elif (ID[0] == 1):
            POS = 26
        elif (ID[0] == 2):
            POS = 27
        elif (ID[0] == 3):
            POS = 28
        elif (ID[0] == 4):
            POS = 29

    if(ID[1] == 1):
        if (ID[0] == 0):
            POS = 30
        elif (ID[0] == 1):
            POS = 31
        elif (ID[0] == 2):
            POS = 32
        elif (ID[0] == 3):
            POS = 33
        elif (ID[0] == 4):
            POS = 34

    if(ID[1] == 2):
        if (ID[0] == 0):
            POS = 35
        elif (ID[0] == 1):
            POS = 36
        elif (ID[0] == 2):
            POS = 37
        elif (ID[0] == 3):
            POS = 38
        elif (ID[0] == 4):
            POS = 39

    if(ID[1] == 3):
        if (ID[0] == 0):
            POS = 40
        elif (ID[0] == 1):
            POS = 41
        elif (ID[0] == 2):
            POS = 42
        elif (ID[0] == 3):
            POS = 43
        elif (ID[0] == 4):
            POS = 44
    if(ID[1] == 4):
        if (ID[0] == 0):
            POS = 45
        elif (ID[0] == 1):
            POS = 46
        elif (ID[0] == 2):
            POS = 47
        elif (ID[0] == 3):
            POS = 48
        elif (ID[0] == 4):
            POS = 49

    return (POS)  