#!/bin/bash
gcc -o app.exe main.c my_funcs.c -Wall -Werror -std=c99 -O0 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage