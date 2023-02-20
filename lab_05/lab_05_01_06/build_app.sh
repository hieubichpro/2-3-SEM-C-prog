#!/bin/bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main.c my_funcs.c -o app.exe
./app.exe