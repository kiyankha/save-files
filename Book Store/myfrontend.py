from tkinter import *
import mybackend


def clear_list():
    list1.delete(0, END)


def fill_list(books):
    for book in books:
        list1.insert(END, book)


window = Tk()
window.title('Book Store')
# ==================================================LABELS=====================================
title = Label(window, text='Title')
title.grid(row=0, column=0)

author = Label(window, text='Author')
author.grid(row=0, column=2)

year = Label(window, text='Year')
year.grid(row=1, column=0)

isbn = Label(window, text='ISBN')
isbn.grid(row=1, column=2)
# ================================================Entries=======================================
title_text = StringVar()
e1 = Entry(window, text=title_text)
e1.grid(row=0, column=1)

author_text = StringVar()
e2 = Entry(window, text=author_text)
e2.grid(row=0, column=3)

year_text = StringVar()
e3 = Entry(window, text=year_text)
e3.grid(row=1, column=1)

isbn_text = StringVar()
e4 = Entry(window, text=isbn_text)
e4.grid(row=1, column=3)

list1 = Listbox(window, width=35, height=6)
list1.grid(row=2, column=0, rowspan=6, columnspan=2)

sb1 = Scrollbar(window)
sb1.grid(row=2, column=2, rowspan=6)

list1.configure(yscrollcommand=sb1.set)
sb1.configure(command=list1.yview)


# example_sb = list1.get(list1.curselection())
# ss = index

# selected_book = ""

def get_selected_row():
    global selected_book
    index = list1.curselection()[0]
    selected_book = list1.get(index)
    # title
    e1.delete(0, END)
    e1.insert(END, selected_book[1])
    # author
    e2.delete(0, END)
    e2.insert(END, selected_book[2])
    # year
    e3.delete(0, END)
    e3.insert(END, selected_book[3])
    # ISBN
    e4.delete(0, END)
    e4.insert(END, selected_book[4])


list1.bind("<<ListBoxSelect>>", get_selected_row)


# =========================================Buttons==========================================

def view_command():
    clear_list()
    books = mybackend.view()
    fill_list(books)


b1 = Button(window, text='View All', width='15', command=view_command)
b1.grid(row=2, column=3)


def search_command():
    clear_list()
    books = mybackend.search(title_text.get(), year_text.get(), author_text.get(), isbn_text.get())
    fill_list(books)


b2 = Button(window, text='Search Book', width='15', command=search_command)
b2.grid(row=3, column=3)


def add_command():
    mybackend.insert(title_text.get(), year_text.get(), author_text.get(), isbn_text.get())
    view_command()


b3 = Button(window, text='Add Entry', width='15', command=add_command)
b3.grid(row=4, column=3)


def update_command():
    mybackend.update([0], title_text.get(), year_text.get(), author_text.get(), isbn_text.get())
    view_command()


b4 = Button(window, text='Update Selected', width='15', command=update_command)
b4.grid(row=5, column=3)


def delete_command():
    mybackend.delete(list1.get(list1.curselection())[0])
    view_command()


b5 = Button(window, text='Delete Selected ', width='15', command=delete_command)
b5.grid(row=6, column=3)

b6 = Button(window, text='Close', width='15', command=window.destroy)
b6.grid(row=7, column=3)

view_command()
window.mainloop()
