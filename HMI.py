import tkinter as tk

HMI = tk.Tk()
HMI.geometry("1200x725")
HMI.title("Bingo Game")

HMI.iconbitmap("Bingo_Icon.ico")

# creating the Label with
# the text Middle
Label_middle = tk.Label(HMI,
                        text ='Middle')
 
# Placing the Label at
# the middle of the root window
# relx and rely should be properly
# set to position the label on
# root window
Label_middle.place(relx = 0.5,
                   rely = 0.5,
                   anchor = 'center')

HMI.mainloop()
