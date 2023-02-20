#!/bin/bash
gcc -std=c99 -c -O2 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion main.c
gcc -std=c99 -c -O2 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion my_funcs.c
gcc -o app.exe main.o my_funcs.c