import ctypes as ct
from tkinter import *
from tkinter import messagebox

def check_number(a):
    try:
        num = int(a)
    except:
        messagebox.showinfo("ERROR", "Invalid number")
        return
    
    return int(a)

def get_arr(where):
    str_arr = where.get().split()
    arr = [check_number(num) for num in str_arr]
    
    if len(arr) < 1:
        messagebox.showinfo("ERROR", "Invalid size")
        return
    return arr
    
def output_arr(arr, size, where):
    where.delete(0, END)

    str_arr = ""
    for num in range(size):
        str_arr += str(arr[num]) + ' '
    
    where.insert(END, str_arr)

def rotate_left(arr, k):
    lib = ct.CDLL("libarr.so")

    _rotate_left = lib.rotate_left
    _rotate_left.argtypes = [ct.POINTER(ct.c_int),
                     ct.c_int, ct.c_int]
    _rotate_left.restype = None
    arr = (ct.c_int * len(arr))(*arr)
    _rotate_left(arr, len(arr), k)

    return arr

def process_rotate_left():
    arr = get_arr(Entry_input_arr_1)

    k = check_number(Entry_input_k.get())

    arr = rotate_left(arr, k)

    output_arr(arr, len(arr), Entry_result_1)

def make_new_arr(arr_src):
    lib = ct.CDLL("libarr.so")

    _make_new_arr = lib.make_new_arr
    _make_new_arr.argtypes = [ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.c_int]
    make_new_arr.restype = ct.c_int

    arr = (ct.c_int * len(arr_src))(*arr_src)
    global how
    if (how.get() == 1):
        arr_set = (ct.c_int * len(arr_src))()
    elif (how.get() == 2):
        arr_set = (ct.c_int * 0)()
        set_size = _make_new_arr(arr_set, arr, len(arr))
        arr_set = (ct.c_int * set_size)(*arr_set)
    arr_size = _make_new_arr(arr_set, arr, len(arr))
    return arr_set, arr_size

def process_make_new_arr():
    arr = get_arr(Entry_input_arr_2)

    arr_new , size_arr = make_new_arr(arr)

    output_arr(arr_new, size_arr, Entry_result_2)

#интерфейс
window = Tk()
window.title("LAB_12")
window.config(bg = "lightgreen")
window.geometry("700x650")
how = IntVar() 
Label_title1 =  Label(window, text = "Задача 1: Сдвига массива на влево", bg = "lightgreen", fg = "red")
Label_title1.place(x = 150, y = 10)

Label_input_arr1 =  Label(window, text = "Ввести массив:", bg = "lightgreen")
Entry_input_arr_1 = Entry(window, width = 40)
Label_input_arr1.place(x = 60, y = 120)
Entry_input_arr_1.place(x = 60, y = 160)

Label_input_size =  Label(window, text = "Ввести к позиций влево:", bg = "lightgreen")
Entry_input_k = Entry(window, width = 40)
Label_input_size.place(x = 60, y = 60)
Entry_input_k.place(x = 60, y = 90)

Button_rotate = Button(window, text = "Запустить", command = lambda: process_rotate_left())
Button_rotate.place(x = 200, y = 200)

Label_result_arr1 =  Label(window, text = "Результат:", bg = "lightgreen")
Entry_result_1 = Entry(window, width = 40)
Label_result_arr1.place(x = 60, y = 230)
Entry_result_1.place(x = 60, y = 270)

Label_title2 =  Label(window, text = "Задача 2: Работать с полными квадратами числами", fg = "red", bg = "lightgreen")
Label_title2.place(x = 80, y = 310)

Label_input_arr2 =  Label(window, text = "Ввести массив:", bg = "lightgreen")
Label_input_arr2.place(x = 60, y = 430)
Entry_input_arr_2 = Entry(window, width = 40)
Entry_input_arr_2.place(x = 60, y = 450)

Button_set = Button(window, text = "Запустить", command = lambda: process_make_new_arr())
Button_set.place(x = 200, y = 480)

Label_result_arr2 =  Label(window, text = "Результат:", bg = "lightgreen")
Entry_result_2 = Entry(window, width = 40)
Label_result_arr2.place(x = 60, y = 520)
Entry_result_2.place(x = 60, y = 550)

Button_quit = Button(window, text = "Quit", command=window.destroy)
Button_quit.place(x = 200, y = 600)


 
how1_checkbutton = Radiobutton(text="Способ 1: выделить максимальную память",
                    value=1, variable=how, justify = LEFT, bd = 1)
how1_checkbutton.select()
how1_checkbutton.place(x = 0, y = 345, width = 670, height = 30, anchor= NW)

how2_checkbutton = Radiobutton(text="Способ 2: выделить требуемый память",
                    value=2, variable=how, justify = LEFT, bd = 1)

how2_checkbutton.place(x = 0, y = 378, width = 670, height = 30, anchor= NW)

window.mainloop()

