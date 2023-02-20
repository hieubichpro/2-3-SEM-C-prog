#!/bin/bash
gcc -std=c99 -c -g3 -O0 -Wall -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla main.c
gcc main.o -o app.exe -lm