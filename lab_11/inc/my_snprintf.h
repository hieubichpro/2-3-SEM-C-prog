#ifndef __MY_SNPRINTF_H__
#define __MY_SNPRINTF_H__

#include "error.h"
#include "my_string.h"
#include "convert.h"

int my_snprintf(char *s, size_t size, const char *format, ...);

char *my_strncat_specifier(char *dest, size_t *str_len, char *spec, va_list arg, size_t max_size);

#endif