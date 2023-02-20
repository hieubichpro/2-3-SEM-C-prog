CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
INC := ./inc/
SRC_STATIC := src_static/
SRC_DYNAMIC := src_dynamic/
LIB := ./lib/
UNIT := ./unit_tests/

all: app_dynamic.exe libarr.so


# app_static.exe: $(SRC_STATIC)main_static.c $(SRC_STATIC)process_sta.c libarr.a
# 	$(CC) $(CFLAGS) -o $@ $^

# libarr.a: filter.o error.o sort.o IO.o
# 	ar rc $@ $^
# 	ranlib $@


app_dynamic.exe: $(SRC_DYNAMIC)main_dynamic.c $(SRC_DYNAMIC)process.c libarr.so $(INC)process.h
	$(CC) -c $^
	$(CC) -o $@ main_dynamic.o process.o -ldl

libarr.so : filter.o error.o sort.o IO.o
	$(CC) -o $@ -shared $^ -ldl

%.o: $(LIB)%.c $(INC)*.h
		$(CC) $(CFLAGS) -I inc -o $@ -c $<

.PHONY : clean
clean:
	rm *.o *.exe libarr.a libarr.so