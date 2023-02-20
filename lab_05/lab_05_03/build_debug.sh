gcc -std=c99 -c -g3 -O0 -Wall -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion main.c
gcc -std=c99 -c -g3 -O0 -Wall -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion my_funcs.c
gcc main.o my_funcs.o -o app.exe