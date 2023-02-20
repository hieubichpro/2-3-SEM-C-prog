CC := gcc
CFLAGS := -Wall -Werror -pedantic -std=c99
INC := inc/
SRC := src/
UNIT := unit_tests/
OBJ := check_main.o check_polynome.o

all: app.exe unit_tests.exe
app.exe: main.o functions.o inout.o polynome.o
	$(CC) -o $@ $^

unit_tests.exe: $(OBJ) inout.o polynome.o
	$(CC) -o $@ $^ -lcheck

%.o: $(SRC)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $<

%.o: $(UNIT)%.c $(INC)*.h $(UNIT)*.h
	$(CC) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm *.o *.exe
