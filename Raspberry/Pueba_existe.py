import WIN_OR_NOT as Test

TB = [['1','2','3','4','5'],['16','17','18','19','20'],['31','32','Y','34','35'],['46','47','48','49','50'],['61','62','63','64','65']]


ID = []

while True:

    print(TB)

    SEE = input("INTRODUZCA VALOR:")

    for i in range(5):
        for j in range(5):
            if (TB[i][j] == SEE):
                ID = [i,j]

    TB[ID[0]][ID[1]] = 'Y'

# TABLA 1 POS

    if(ID[0] == 0):
        if (ID[1] == 0):
            POS = 4
        elif (ID[1] == 1):
            POS = 3
        elif (ID[1] == 2):
            POS = 2
        elif (ID[1] == 3):
            POS = 1
        elif (ID[1] == 4):
            POS = 0

    if(ID[0] == 1):
        if (ID[1] == 0):
            POS = 9
        elif (ID[1] == 1):
            POS = 8
        elif (ID[1] == 2):
            POS = 7
        elif (ID[1] == 3):
            POS = 6
        elif (ID[1] == 4):
            POS = 5

    if(ID[0] == 2):
        if (ID[1] == 0):
            POS = 14
        elif (ID[1] == 1):
            POS = 13
        elif (ID[1] == 2):
            POS = 12
        elif (ID[1] == 3):
            POS = 11
        elif (ID[1] == 4):
            POS = 10

    if(ID[0] == 3):
        if (ID[1] == 0):
            POS = 19
        elif (ID[1] == 1):
            POS = 18
        elif (ID[1] == 2):
            POS = 17
        elif (ID[1] == 3):
            POS = 16
        elif (ID[1] == 4):
            POS = 15


    if(ID[0] == 4):
        if (ID[1] == 0):
            POS = 24
        elif (ID[1] == 1):
            POS = 23
        elif (ID[1] == 2):
            POS = 22
        elif (ID[1] == 3):
            POS = 21
        elif (ID[1] == 4):
            POS = 20


# TABLA 2 POS
    if(ID[0] == 0):
        if (ID[1] == 0):
            POS = 29
        elif (ID[1] == 1):
            POS = 28
        elif (ID[1] == 2):
            POS = 27
        elif (ID[1] == 3):
            POS = 26
        elif (ID[1] == 4):
            POS = 25

    if(ID[0] == 1):
        if (ID[1] == 0):
            POS = 34
        elif (ID[1] == 1):
            POS = 33
        elif (ID[1] == 2):
            POS = 32
        elif (ID[1] == 3):
            POS = 31
        elif (ID[1] == 4):
            POS = 30

    if(ID[0] == 2):
        if (ID[1] == 0):
            POS = 39
        elif (ID[1] == 1):
            POS = 38
        elif (ID[1] == 2):
            POS = 37
        elif (ID[1] == 3):
            POS = 36
        elif (ID[1] == 4):
            POS = 35

    if(ID[0] == 3):
        if (ID[1] == 0):
            POS = 44
        elif (ID[1] == 1):
            POS = 43
        elif (ID[1] == 2):
            POS = 42
        elif (ID[1] == 3):
            POS = 41
        elif (ID[1] == 4):
            POS = 40


    if(ID[0] == 4):
        if (ID[1] == 0):
            POS = 49
        elif (ID[1] == 1):
            POS = 48
        elif (ID[1] == 2):
            POS = 47
        elif (ID[1] == 3):
            POS = 46
        elif (ID[1] == 4):
            POS = 45

    print (POS)
    if(Test.CONFIRM(TB)):    
        print("WINNER")
        break
