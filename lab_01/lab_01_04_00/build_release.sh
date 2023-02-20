#!/bin/bash
gcc -std=c99 -c -O2 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion main.c
gcc -o app.exe main.o -lm
