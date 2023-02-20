CFLAGS := -std=c99 -Wall -Werror -ggdb

app.exe: main.o my_malloc.o
	gcc -o app.exe main.o my_malloc.o

my_malloc.o: my_malloc.c my_malloc.h
	gcc $(CFLAGS) -c my_malloc.c

main.o: main.c my_malloc.h
	gcc $(CFLAGS) -c main.c

clean:
	$(RM) *.o *.exe
