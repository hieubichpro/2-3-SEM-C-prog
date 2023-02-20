CC := gcc
CFLAGS := -Wall -Werror -pedantic -std=c99
INC := inc/
SRC := src/
UNIT := unit_tests/
OBJ := check_main.o check_pop.o check_reverse.o check_sort.o

all: app.exe unit_tests.exe

app.exe: main.o functions.o
	$(CC) -o $@ $^

unit_tests.exe: $(OBJ) functions.o
	$(CC) -o $@ $^ -lcheck

%.o: $(SRC)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $<

%.o: $(UNIT)%.c $(INC)*.h $(UNIT)*.h
	$(CC) $(CFLAGS) -c $<

.PHONY : clean run unit
clean:
	rm *.o *.exe

run:
	./app.exe

unit:
	./unit_tests.exe
