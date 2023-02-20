#!/bin/bash
gcc -c main.c -Wall -Werror -std=c99 -O0 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla --coverage
gcc main.o -o app.exe --coverage -lm