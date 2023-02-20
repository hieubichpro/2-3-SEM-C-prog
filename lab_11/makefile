CC := gcc 
FLAGS := -std=c99 -Wall -Werror -pedantic
INC := ./inc/
SRC := ./src/
UNIT := ./unit_tests/

OBJ := main.o my_string.o my_snprintf.o convert.o

all: app.exe 

app.exe : $(OBJ) $(INC)*.h
	$(CC) $(FLAGS) -o $@ $^ -lm

# unit_tests.exe:	check_main.o check_my_string.o my_string.o my_snprintf.o
# 	$(CC) $(CFLAGS) -o $@ $^ -lcheck -l

%.o: $(SRC)%.c $(INC)*.h
	$(CC) $(FLAGS) -c $< -o $@

%.o: $(UNIT)%.c $(INC)*.h $(UNIT)*.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : clean unit func
clean:
	rm -rf *.exe *.o
	rm -rf ./func_tests/data/*_out_test.txt

unit: unit_tests.exe
	./unit_tests.exe

func: