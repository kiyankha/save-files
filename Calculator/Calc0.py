from tkinter import *

root = Tk()

# =============================================Settings==============================================
root.title('Calculator')
root.geometry('650x500')
root.resizable(width=True, height=False)
color = 'gray'
root.configure(bg=color)

# =============================================Frames==============================================
top_frame_1 = Frame(root, width=650, height=125, bg=color)
top_frame_1.pack(side=TOP)

top_frame_2 = Frame(root, width=650, height=125, bg=color)
top_frame_2.pack(side=TOP)

top_frame_3 = Frame(root, width=650, height=125, bg=color)
top_frame_3.pack(side=TOP)

top_frame_4 = Frame(root, width=650, height=125, bg=color)
top_frame_4.pack(side=TOP)
# ==============================================Buttons=====================================
btn_plus = Button(top_frame_3, text='+', width=10, )
btn_plus.pack(side=LEFT, padx=5, pady=5)

btn_minus = Button(top_frame_3, text='-', width=10)
btn_minus.pack(side=LEFT, padx=5, pady=5)

btn_mul = Button(top_frame_3, text='*', width=10)
btn_mul.pack(side=LEFT, padx=5, pady=5)

btn_div = Button(top_frame_3, text='/', width=10)
btn_div.pack(side=LEFT, padx=5, pady=5)

# ============================================Entries & Labels=========================================
label_first_num = Label(top_frame_1, text='please enter the first number')
label_first_num.pack(side=LEFT, padx=5, pady=10)

first_num = Entry(top_frame_1)
first_num.pack(side=LEFT)

label_second_num = Label(top_frame_2, text='please enter the second number')
label_second_num.pack(side=LEFT, padx=5, pady=5)

second_num = Entry(top_frame_2)
second_num.pack(side=LEFT)

res_label = Label(top_frame_4, text='Result = ')
res_label.pack(side=LEFT)

res_num = Entry(top_frame_4)
res_num.pack(side=LEFT, padx=25, pady=5)

root.mainloop()
