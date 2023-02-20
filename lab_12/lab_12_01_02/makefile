CC := gcc
CFLAGS := -std=c99 -Wall -Werror
UNIPATH := ./unit_tests/
LIBPATH := ./lib/

all : libarr.so
#библиотека

arr_lib.o : $(LIBPATH)arr_lib.c $(LIBPATH)arr_lib.h
	$(CC) $(CFLAGS) -c $<

libarr.so : arr_lib.o
	$(CC) -o $@ -shared arr_lib.o
	
.PHONY : clean unit check_mem_unit run
clean :
	$(RM) *.o *.exe *.d *.dll

unit : unit_tests.exe
	./unit_tests.exe
	
run : libarr.so main.py
	python3 main.py