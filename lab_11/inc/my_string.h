#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include "error.h"

#define D_ALPHABET "0123456789"
#define X_ALPHABET "0123456789abcdef"

size_t my_strlen(char const *str);

char *my_strchr(char *str, char ch);

void *my_memset(void *str, int value, size_t size);

int my_strncat(char *dest, char *src, int n, size_t max_size);

int add_char(char *dest, char ch, size_t max_size);

#endif