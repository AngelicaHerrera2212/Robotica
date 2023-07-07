import numpy as np

Y = 0

Table1 = (2,19,44,48,67,
         15,23,39,54,70,
         8,29,Y,46,69,
         12,27,42,50,72,
         6,21,37,55,75)

Table2 = (9,28,32,57,71,
          7,26,34,50,74,
          3,22,Y,47,70,
          11,21,43,51,75,
          4,19,35,53,61)

Table3 = (1,16,33,56,62,
          4,29,40,46,75,
          13,17,Y,58,66,
          10,25,36,60,64,
          2,18,44,57,72)

Table4 = (3,20,36,49,64,
          8,18,43,52,71,
          9,24,Y,57,68,
          14,17,38,48,73,
          1,29,41,59,70)

Table5 = (5,17,31,50,73,
          9,21,44,48,63,
          1,28,Y,59,74,
          13,20,37,52,66,
          8,16,32,46,71)

Tables = (Table1,Table2,Table3,Table4,Table5)

WinList = {"V1":(0,1,2,3,4),
           "V2":(5,6,7,8,9),
           "V3":(10,11,12,13,14),
           "V4":(15,16,17,18,19),
           "V5":(20,21,22,23,24),
           "H1":(0,5,10,15,20),
           "H2":(1,6,11,16,21),
           "H3":(2,7,12,17,22),
           "H4":(3,8,13,18,23),
           "H5":(4,9,14,19,24),
           "D1":(0,6,12,18,24),
           "D2":(4,8,12,16,20)}

test = (1,12,16,8,20,55,21,7,7,8,3,5,4)
Ilist = []

def PosTable(Input,Table):
    try:
        Position = Table.index(Input)
        return Position
    except:
        pass

def Win(x):
    for Keys in WinList:
        List = set(WinList[Keys])

        if List.issubset(set(x)):
            print(f'yes {Keys}')
            print("Win!!!!!!!!!!!!!!!!!!!!!!!!!")
        else:
            print('no')

while True:
    Input = int(input('Favor añada un numero: '))
    Ilist.append(PosTable(Input,Table1))
    Win(Ilist)