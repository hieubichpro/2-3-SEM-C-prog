#ifndef _IO_H_
#define _IO_H_

#include "struct.h"
#include "functions.h"
#include "list.h"
#include "memory.h"
#include "polynome.h"

int input_elem(int *coeff, int *power);

int input_polynome(list_t *f);

void print_polynome(list_t *f);

#endif