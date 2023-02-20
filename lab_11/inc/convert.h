#ifndef __CONVERT_H__
#define __CONVERT_H__

#include "error.h"
#include "my_string.h"

#define D_ALPHABET "0123456789"
#define X_ALPHABET "0123456789abcdef"

int convert_long_number_to_string(char *dest, long int number, char type_base, size_t max_size);

#endif