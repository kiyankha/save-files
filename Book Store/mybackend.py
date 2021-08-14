import sqlite3


def connect():
    conn = sqlite3.connect("books.db")
    cur = conn.cursor()
    cur.execute(
        "CREATE TABLE IF NOT EXISTS book (id INTEGER PRIMARY KEY, title text, author text, year INTEGER, ISBN INTEGER)")
    conn.commit()
    conn.close()


def insert(title, year, author, ISBN):
    conn = sqlite3.connect('books.db')
    cur = conn.cursor()
    cur.execute("INSERT INTO book VALUES (NULL ,?,?,?,?)", (title, year, author, ISBN))
    conn.commit()
    conn.close()


def view():
    conn = sqlite3.connect('books.db')
    cur = conn.cursor()
    cur.execute("SELECT * FROM book")
    rows = cur.fetchall()
    conn.commit()
    conn.close()
    return rows


def search(title='', year='', author='', ISBN=''):
    conn = sqlite3.connect("books.db")
    cur = conn.cursor()
    cur.execute("SELECT * FROM book WHERE title=? or year=? or author=? or ISBN=?", (title, year, author, ISBN))
    rows = cur.fetchall()
    conn.commit()
    return rows


def delete(id):
    conn = sqlite3.connect("books.db")
    cur = conn.cursor()
    cur.execute("DELETE FROM book WHERE id=?", (id,))
    conn.commit()
    conn.close()


def update(id, title, year, author, ISBN):
    conn = sqlite3.connect("books.db")
    cur = conn.cursor()
    cur.execute("UPDATE book SET title=?,year=?,author=?,ISBN=?", (title, year, author, ISBN, id))
    conn.commit()
    conn.close()


connect()
# insert("Sea", "kian", 2021, 872340)
# insert('eye', 'reza',2019,829375)
# insert('world', 'akbar',2012,839375)
# insert('animal', 'ali',2001,867375)


