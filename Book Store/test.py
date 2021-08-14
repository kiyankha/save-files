from tkinter import *

root = Tk()

root.title('test')
l1= Listbox(root,width=10,height=10)
l1.grid(row=0,column=0)

def kk():
    global sel

    sel = l1.curselection()




root.mainloop()

