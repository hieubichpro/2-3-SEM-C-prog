#ifndef _POLYNOME_H_
#define _POLYNOME_H_

#include "struct.h"
#include "functions.h"
#include "io.h"
#include "list.h"
#include "memory.h"

int calc_value(list_t *src, const int value);

void derivative(list_t *f);

void pop_end(list_t *f);

void sum(iter_t *i, iter_t *j);

void shift_left(iter_t *it, int cnt);

void plus(list_t *f1, list_t *f2);

int degree(list_t *f);

void print(iter_t *it);

void devide_polynome(list_t *f, list_t *even, list_t *odd);

#endif