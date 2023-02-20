#!/bin/bash
gcc -c main.c -o app.o -Wall -Werror -std=c99 -O0 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla --coverage
gcc app.o -o app.exe --coverage -lm