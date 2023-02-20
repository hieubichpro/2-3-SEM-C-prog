#ifndef __ITEM_H__
#define __ITEM_H__

#include "check_IO.h"

typedef struct
{
    char title[STRING_MAX + 1];
    double weight;
    double volume;
} item;

int starts_with_substr(const item *a, const char *s);
double get_density(const item item);
void fill_arr_density(const item *const items_array, const int items_len, double *arr_density);
int curr_is_greater_than_next(const double curr, const double next);
void swap_two_densities(double *density_1, double *density_2);
void swap_two_items(item *item_1, item *item_2);

void item_print(const item *a);
void print_data(const item a[], int n);
void print_data_by_filter(const item a[], size_t n, const char *substr);
void sort_by_density(item *items_array, int items_len);
void sort_and_print_data(item *items_array, int items_len);

#endif