import tkinter.messagebox
from tkinter import *

root = Tk()
root.title("Calculator")
root.geometry("650x500")
root.configure(bg='green')

num_1 = StringVar()
num_2 = StringVar()
Result = StringVar()
# =========================================Labels===========================================
firstnum_label = Label(root, text="Enter the first number", font="Arial 15").place(x=100, y=5, width=200, height=25)
secondnum_label = Label(root, text="Enter the second number", font="Arial 15").place(x=100, y=40, width=230, height=25)
result_label = Label(root, text="Result", font="Arial 15").place(x=100, y=90, width=200, height=25)
result_label2 = Label(root, textvariable=Result, font="Arial 19").place(x=350, y=90, width=200, height=40)


# ===========================================Functions===========================================

def errormsg(msg):
    if msg == "Error":
        tkinter.messagebox.showerror("Error", 'something went wrong')
    elif msg == "Division by 0 error":
        tkinter.messagebox.showerror("Error", "Don't Divide by 0")


def plus():
    try:
        value = float(num_1.get()) + float(num_2.get())
        Result.set(value)
    except:
        errormsg('Error')


def minus():
    try:
        value = float(num_1.get()) - float(num_2.get())
        Result.set(value)
    except:
        errormsg('Error')


def multiply():
    try:
        value = float(num_1.get()) * float(num_2.get())
        Result.set(value)
    except:
        errormsg("Error")


def division():
    if num_2.get() == '0':
        errormsg("Division by 0 error")
    elif num_2.get() != '0':
        try:
            value = float(num_1.get())/float(num_2.get())
            Result.set(value)
        except:
            errormsg('Error')


#  ========================================Entries==========================================
firstnum_entry = Entry(root, textvariable=num_1, font='Arial 18').place(x=350, y=5, width=100, height=25)
secondnum_entry = Entry(root, textvariable=num_2, font='Arial 18').place(x=350, y=40, width=100, height=25)

# ============================================Buttons========================================
plus_button = Button(root, text='+', font="Arial 30", command=plus).place(x=100, y=200, width=70, height=70)
minus_button = Button(root, text='-', font="Arial 40", command=minus).place(x=190, y=200, width=70, height=70)
multiply_button = Button(root, text='*', font="Arial 40", command=multiply).place(x=100, y=300, width=70, height=70)
division_button = Button(root, text='/', font="Arial 40", command=division).place(x=190, y=300, width=70, height=70)

root.mainloop()
