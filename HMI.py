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
                self.serial.write(Message)
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
    
def image():
    #The function cv2.imread() is used to read an image.
    img_grayscale = cv2.imread('test.jpg')
    
    #The function cv2.imshow() is used to display an image in a window.
    cv2.imshow('graycsale image',img_grayscale)
    
    #waitKey() waits for a key press to close the window and 0 specifies indefinite loop
    #cv2.waitKey(0)
    
    #cv2.destroyAllWindows() simply destroys all the windows we created.
    
if __name__ == '__main__':

   # Create an instance of the SerialPortConnection class
    serial_connection = SerialPortConnection("", 9600)

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
    Widgets.Create_Button("Enter",350,142,('Cambria',8,'bold'),lambda : serial_connection.SendMessage(B_List.get()))
    Widgets.Create_Button("Enter",350,221,('Cambria',8,'bold'),lambda : serial_connection.SendMessage(I_List.get()))
    Widgets.Create_Button("Enter",350,305,('Cambria',8,'bold'),lambda : serial_connection.SendMessage(N_List.get()))
    Widgets.Create_Button("Enter",350,389,('Cambria',8,'bold'),lambda : serial_connection.SendMessage(G_List.get()))
    Widgets.Create_Button("Enter",350,474,('Cambria',8,'bold'),lambda : serial_connection.SendMessage(O_List.get()))

    #Widgets.Create_Button("Start!",625,300,('Cambria',15,'bold'),lambda : serial_connection.SendMessage("Start"))
    Widgets.Create_Button("Start!",625,300,('Cambria',15,'bold'),image)

    #Serial Comunication------------------------------------------------
    Widgets.Create_Label('Port',553,54,'white',('Cambria',12,'bold'))
    Widgets.Create_Label('Baudrate',553,119,'white',('Cambria',12,'bold'))

    # Get available ports
    PortList = serial_connection.get_available_ports()
    BaudrateList = (9600,38400,57600,115200)

    Port_Combobox = Widgets.Create_ComboBox(PortList,675,54,15)
    Baudrate_Combobox = Widgets.Create_ComboBox(BaudrateList,675,119,15)

    x = 525
    Widgets.Create_Button("Open",38+x,192,('Cambria',8,'bold'),lambda : serial_connection.open_port(Port_Combobox,Baudrate_Combobox))
    Widgets.Create_Button("Refresh",136+x,192,('Cambria',8,'bold'),serial_connection.Refresh_Ports)
    Widgets.Create_Button("Close",233+x,192,('Cambria',8,'bold'),serial_connection.close_port)
    
    #Students
    Widgets.Create_Label('Angélica Herrera - 1093629\nWisleiny Lara - 1090359',875,565,'white',('Cambria',12,'bold'),'right','se')

    HMI.protocol("WM_DELETE_WINDOW",serial_connection.Close_Port_DestroyWindow)
    HMI.mainloop()