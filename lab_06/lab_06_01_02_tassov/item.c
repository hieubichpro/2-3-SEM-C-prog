#include "item.h"

int starts_with_substr(const item *a, const char *s)
{
    return strncmp(a->title, s, strlen(s)) == 0;
}

void item_print(const item *a)
{
    printf("%s\n%lf\n%lf\n", a->title, a->weight, a->volume);
}

void print_data(const item a[], int n)
{
    for (int i = 0; i < n; i++)
        item_print(&a[i]);
}

void print_data_by_filter(const item a[], size_t n, const char *substr)
{
    for (size_t i = 0; i < n; i++)
        if (starts_with_substr(&a[i], substr))
            item_print(&a[i]);
}

double get_density(const item item)
{
    return item.weight / item.volume;
}

void fill_arr_density(const item *const items_array, const int items_len, double *arr_density)
{
    for (int i = 0; i < items_len; i++)
        arr_density[i] = get_density(items_array[i]);
}

void swap_two_densities(double *density_1, double *density_2)
{
    double temp = *density_1;
    *density_1 = *density_2;
    *density_2 = temp;
}

void swap_two_items(item *item_1, item *item_2)
{
    item temp = *item_1;
    *item_1 = *item_2;
    *item_2 = temp;
}

int curr_is_greater_than_next(const double curr, const double next)
{
    return (curr - next > 1e-15) ? 1 : 0;
}

void sort_by_density(item *items_array, int items_len)
{
    double arr_density[ARRAY_MAX];
    fill_arr_density(items_array, items_len, arr_density);
    int flag = 1;
    for (int i = 0; flag && i < items_len - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < items_len - 1 - i; j++)
        {
            if (curr_is_greater_than_next(arr_density[j], arr_density[j + 1]))
            {
                swap_two_densities(&arr_density[j], &arr_density[j + 1]);
                swap_two_items(&items_array[j], &items_array[j + 1]);
                flag = 1;
            }
        }
    }
}

void sort_and_print_data(item *items_array, int items_len)
{
    sort_by_density(items_array, items_len);
    print_data(items_array, items_len);
}