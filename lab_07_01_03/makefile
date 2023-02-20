CC := gcc
CFLAGS := -std=c99 -Wall -Werror 
INC := inc/
SRC := src/
release: CFLAGS += -pedantic 
release: app.exe
debug: CFLAGS += -g3
debug: app.exe


app.exe: main.o filter.o functions.o sort.o
	$(CC) -o $@ $^

unit_tests.exe: unit_tests.o
	$(CC) -o $@ $^

%.o: $(SRC)%.c $(INC)*.h
	$(CC) $(CFLAGS) -c $<

unit_tests.o: unit_tests/unit_tests.c $(INC)*.h
	$(CC) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm *.o *.exe

.PHONY : unit release debug
unit: unit_tests.exe
	./unit_tests.exe
#func_test