import tkinter as tk
from tkinter import ttk
import serial

class GUI():
    def __init__(self,Window):
        self.Window = Window

    def Create_Label(self,Message,X_Pos,Y_Pos,Color = 'black', Font = ('Arial',25)):
        tk.Label(self.Window, text=Message, fg= Color , font= Font).place(x=X_Pos, y=Y_Pos ,anchor='nw')

    def Create_ComboBox(self,Values,X_Pos,Y_Pos):
        List = ttk.Combobox(self.Window, values=B_Values,width=10)
        List.set(Values[0])
        List.place(x=X_Pos, y=Y_Pos, anchor='nw')
        return List

    def Create_Button(self,Message,X_Pos,Y_Pos,Function=None):
        Button = tk.Button(self.Window, text=Message,command=Function)
        Button.place(x=X_Pos, y=Y_Pos, anchor='nw')
        return Button


if __name__ == '__main__':

    HMI = tk.Tk()
    HMI.geometry("1200x765")
    HMI.title("BingoGO")
    HMI.resizable(0,0) # this removes the maximize button

    HMI.iconbitmap("Bingo_Icon.ico")
    
    # Adding combobox drop down list
    B_Values = (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)
    I_Values = (16,17,18,19,20,21,22,23,24,25,26,27,28,29,30)
    N_Values = (31,32,33,34,35,36,37,38,39,40,41,42,43,44,45)
    G_Values = (46,47,48,49,50,51,52,53,54,55,56,57,58,59,60)
    O_Values = (61,62,63,64,65,66,67,68,69,70,71,72,73,74,75)

    Widgets = GUI(HMI)

    Widgets.Create_Label("START PLAYING!",108,20)

    #BINGO letters
    Widgets.Create_Label("B",56,119,'#65A8E1',('Headline R',28))
    Widgets.Create_Label("I",56,225,'#65A8E1',('Headline R',28))
    Widgets.Create_Label("N",56,338,'#65A8E1',('Headline R',28))
    Widgets.Create_Label("G",56,453,'#65A8E1',('Headline R',28))
    Widgets.Create_Label("O",56,566,'#65A8E1',('Headline R',28))

    #Type a number
    Widgets.Create_Label("Type a number (1-15)" ,155,92)
    Widgets.Create_Label("Type a number (16-30)",155,192)
    Widgets.Create_Label("Type a number (31-45)",155,309)
    Widgets.Create_Label("Type a number (46-60)",155,417)
    Widgets.Create_Label("Type a number (61-75)",155,534)

    #ComboBox Bingo
    B_Values = Widgets.Create_ComboBox(B_Values,150,131)
    I_Values = Widgets.Create_ComboBox(I_Values,150,239)
    N_Values = Widgets.Create_ComboBox(N_Values,150,352)
    G_Values = Widgets.Create_ComboBox(G_Values,150,466)
    O_Values = Widgets.Create_ComboBox(O_Values,150,582)

    #Buttons BINGO
    Widgets.Create_Button("Enter",435,131)
    Widgets.Create_Button("Enter",435,239)
    Widgets.Create_Button("Enter",435,352)
    Widgets.Create_Button("Enter",435,466)
    Widgets.Create_Button("Enter",435,582)

    #Serial Comunication
    Widgets.Create_Button("Open",38,192)
    Widgets.Create_Button("Refresh",136,192)
    Widgets.Create_Button("Close",233,192)
    Widgets.Create_Label('Port',33,54)
    Widgets.Create_Label('Baudrate',33,119)

    BaudrateList = ('9600','38400','57600','115200')
    PortList = ('0')

    Widgets.Create_ComboBox(PortList,173,54)
    Widgets.Create_ComboBox(BaudrateList,173,119)

    HMI.mainloop()