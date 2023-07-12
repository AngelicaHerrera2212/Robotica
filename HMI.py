import tkinter as tk
from tkinter import ttk
import serial
import serial.tools.list_ports
import cv2

class GUI():
    def __init__(self,Window):
        self.Window = Window
        self.parent_bg = self.Window.cget('bg')
        self.canvas = tk.Canvas(self.Window)

    def Create_Label(self,Message,X_Pos,Y_Pos,Color = 'black', Font = ('Arial',25),JustifyText='center',AnchorText='nw'):
        tk.Label(self.Window, text=Message, fg= Color , bg=self.parent_bg , font= Font,justify=JustifyText).place(x=X_Pos, y=Y_Pos ,anchor=AnchorText)

    def Create_ComboBox(self,ValuesList,X_Pos,Y_Pos,WidthSize=25):
        List = ttk.Combobox(self.Window, values=ValuesList,width=WidthSize,height=23)
        List.place(x=X_Pos, y=Y_Pos, anchor='nw')
        try:
            List.set(ValuesList[0])
        except:
            pass
        return List

    def Create_Button(self,Message,X_Pos,Y_Pos,Font = ('Arial',25),Function=None):
        Button = tk.Button(self.Window, font= Font, text=Message, width=10, command=Function)
        Button.place(x=X_Pos, y=Y_Pos, anchor='nw')
        return Button
    
    def Create_Rectangle(self, x1, y1, x2, y2, outline='black', width=1):
        self.canvas.create_rectangle(x1, y1, x2, y2, outline=outline, fill=self.parent_bg, width=width)
        self.canvas.pack()

    def EnableWidgets(self,Widgets,Enable_Disable):
        if type(Widgets) is list:
            for Widget in Widgets:
                Widget["state"] = Enable_Disable
        else:
            Widgets["state"] = Enable_Disable


class SerialPortConnection:
    def __init__(self, port, baudrate):
        self.port = port
        self.baudrate = baudrate
        self.serial = None

    def open_port(self,Ports,Baudrates):
        self.port = Ports.get()
        self.baudrate = int(Baudrates.get())

        try:
            self.serial = serial.Serial(self.port, self.baudrate)
            print("Serial port opened successfully.")
        except serial.SerialException as error:
            print("Error opening serial port:", str(error))

    def close_port(self):
        if self.serial is not None and self.serial.is_open:
            self.serial.close()
            print("Serial port closed.")
        else:
            print('There is no open communication.')
 
    def Refresh_Ports(self):
        # Clear the existing options in the port_combobox
        Port_Combobox['values'] = ()

        # Get the updated list of available ports
        available_ports = self.get_available_ports()

        # Set the new options in the port_combobox
        Port_Combobox['values'] = available_ports
        print('Refreshed')

    def SendMessage(self,Text):
        Message = "<"+str(Text)+">"

        if self.serial is not None and self.serial.is_open:
            try:
                self.serial.write(Message.encode())
                print(f"Message sent: {Message}")
            except serial.SerialException as e:
                print("Error sending message:", str(e))
        else:
            print('There is no open communication.')
            print(Message)
    
    def Close_Port_DestroyWindow(self):
        self.close_port()
        HMI.destroy()

    @staticmethod
    def get_available_ports():
        ports = []
        for port in serial.tools.list_ports.comports():
            ports.append(port.device)
        return ports

class Camera():
    def __init__(self,index=0):
        self.Cap = cv2.VideoCapture(index)

    def TakePic(self):
        if self.Cap.isOpened():
            ret,self.frame = self.Cap.read()
            #self.Cap.release() #releasing camera immediately after capturing picture
            if ret and self.frame is not None:
                cv2.imwrite('Original.jpg', self.frame)
                cv2.imshow('original', self.frame)

class DetectMatrix():
    def __init__(self):
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

        self.Tables = (Table1,Table2,Table3,Table4,Table5)

        self.PositionList = []
        self.Table = None

        self.WinList = {"V1":(0,1,2,3,4),
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

    def key_pressed(self,event):
        if event.char == '2':
            self.Table = self.Tables[0]
            print(f"Key:{event.char}")
        elif event.char == '9':
            self.Table = self.Tables[1]
            print(f"Key:{event.char}")
        elif event.char == '1':
            self.Table = self.Tables[2]
            print(f"Key:{event.char}")
        elif event.char == '3':
            self.Table = self.Tables[3]
            print(f"Key:{event.char}")
        elif event.char == '5':
            self.Table = self.Tables[4]
            print(f"Key:{event.char}")

    def PosTable(self,Input):
        if self.Table is not None:
            if type(Input) == str: 
                Input = int(Input)

            try:
                Position = self.Table.index(Input)
                self.PositionList.append(Position)
                print(self.PositionList)
                self.Win()
            except:
                print('not in table')
                pass
        
    def Win(self):
        for Keys in self.WinList:
            List = set(self.WinList[Keys])

            if List.issubset(set(self.PositionList)):
                print('Ganaste!')

if __name__ == '__main__':
   # Create an instance of the SerialPortConnection class
    serial_connection = SerialPortConnection("", 9600)

    Camera = Camera(0)
    Matrix = DetectMatrix()

    HMI = tk.Tk()
    HMI.geometry("885x575")
    HMI.title("BingoGO")
    HMI.resizable(0,0) # this removes the maximize button
    HMI.configure(bg='#444444')
    HMI.iconbitmap("Bingo_Icon.ico")
    
    # Adding combobox drop down list
    B_Values = (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)
    I_Values = (16,17,18,19,20,21,22,23,24,25,26,27,28,29,30)
    N_Values = (31,32,33,34,35,36,37,38,39,40,41,42,43,44,45)
    G_Values = (46,47,48,49,50,51,52,53,54,55,56,57,58,59,60)
    O_Values = (61,62,63,64,65,66,67,68,69,70,71,72,73,74,75)

    Widgets = GUI(HMI)

    Widgets.Create_Label("START PLAYING!",108,20,'white',('Microsoft Sans Serif',28))

    #Widgets.Create_Rectangle(30, 30, 30, 30, outline='white', width=1)

    #BINGO letters
    Widgets.Create_Label("B",83,133,'#98FB98',('Microsoft Sans Serif',28,'bold'))
    Widgets.Create_Label("I",83,211,'#FA8072',('Microsoft Sans Serif',28,'bold'))
    Widgets.Create_Label("N",83,294,'#00BFFF',('Microsoft Sans Serif',28,'bold'))
    Widgets.Create_Label("G",83,379,'#FFD700',('Microsoft Sans Serif',28,'bold'))
    Widgets.Create_Label("O",83,462,'#DDA0DD',('Microsoft Sans Serif',28,'bold'))

    
    #Type a number
    Widgets.Create_Label("Type a number (1-15)" ,150,113,'white',('Cambria',10,'bold'))
    Widgets.Create_Label("Type a number (16-30)",150,187,'white',('Cambria',10,'bold'))
    Widgets.Create_Label("Type a number (31-45)",150,273,'white',('Cambria',10,'bold'))
    Widgets.Create_Label("Type a number (46-60)",150,353,'white',('Cambria',10,'bold'))
    Widgets.Create_Label("Type a number (61-75)",150,439,'white',('Cambria',10,'bold'))


    #ComboBox Bingo
    B_List = Widgets.Create_ComboBox(B_Values,160,142)
    I_List = Widgets.Create_ComboBox(I_Values,160,221)
    N_List = Widgets.Create_ComboBox(N_Values,160,305)
    G_List = Widgets.Create_ComboBox(G_Values,160,389)
    O_List = Widgets.Create_ComboBox(O_Values,160,474)

    #Buttons BINGO
    B_Button = Widgets.Create_Button("Enter",350,142,('Cambria',8,'bold'),lambda : [serial_connection.SendMessage(B_List.get()), Matrix.PosTable(B_List.get())])
    I_Button = Widgets.Create_Button("Enter",350,221,('Cambria',8,'bold'),lambda : [serial_connection.SendMessage(I_List.get()), Matrix.PosTable(I_List.get())])
    N_Button = Widgets.Create_Button("Enter",350,305,('Cambria',8,'bold'),lambda : [serial_connection.SendMessage(N_List.get()), Matrix.PosTable(N_List.get())])
    G_Button = Widgets.Create_Button("Enter",350,389,('Cambria',8,'bold'),lambda : [serial_connection.SendMessage(G_List.get()), Matrix.PosTable(G_List.get())])
    O_Button = Widgets.Create_Button("Enter",350,474,('Cambria',8,'bold'),lambda : [serial_connection.SendMessage(O_List.get()), Matrix.PosTable(O_List.get())])

    Start_Button = Widgets.Create_Button("Start!",625,300,('Cambria',15,'bold'),lambda : serial_connection.SendMessage("Start"))
    TakePic_Button = Widgets.Create_Button("Take Pic",625,350,('Cambria',15,'bold'),Camera.TakePic)

    #Serial Comunication------------------------------------------------
    Widgets.Create_Label('Port',553,54,'white',('Cambria',12,'bold'))
    Widgets.Create_Label('Baudrate',553,119,'white',('Cambria',12,'bold'))

    # Get available ports
    PortList = serial_connection.get_available_ports()
    BaudrateList = (9600,38400,57600,115200)

    Port_Combobox = Widgets.Create_ComboBox(PortList,675,54,15)
    Baudrate_Combobox = Widgets.Create_ComboBox(BaudrateList,675,119,15)

    x = 525
    Refresh_Button = Widgets.Create_Button("Refresh",136+x,192,('Cambria',8,'bold'),serial_connection.Refresh_Ports)
    Close_Button = Widgets.Create_Button("Close",233+x,192,('Cambria',8,'bold'),serial_connection.close_port)
    Open_Button = Widgets.Create_Button("Open",38+x,192,('Cambria',8,'bold'),lambda : serial_connection.open_port(Port_Combobox,Baudrate_Combobox))

    #Students
    Widgets.Create_Label('Angélica Herrera - 1093629\nWisleiny Lara - 1090359',875,565,'white',('Cambria',12,'bold'),'right','se')

    WidgetsList = [B_List,I_List,N_List,G_List,O_List,
               B_Button,I_Button,N_Button,G_Button,O_Button,
               Start_Button,TakePic_Button]
    
    #Widgets.EnableWidgets(WidgetsList,"disabled")

    HMI.bind('<Key>', Matrix.key_pressed)
    #HMI.protocol("WM_DELETE_WINDOW",lambda : [serial_connection.Close_Port_DestroyWindow, Camera.Cap.release()])
    HMI.protocol("WM_DELETE_WINDOW",serial_connection.Close_Port_DestroyWindow)
    HMI.mainloop()