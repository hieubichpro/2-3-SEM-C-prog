#include "arr_lib.h"

void rotate_left(int *arr, int len, int k)
{
    for (int i = 0 ; i < k; i++)
    {
        int temp = arr[0];
        for (int i = 0; i < len - 1; i++)
            arr[i] = arr[i + 1];
        arr[len - 1] = temp;
    }
}

int check_sqr(int number)
{
    int sq_num = (int) sqrt((double) number);
    return sq_num * sq_num == number;
}

int make_new_arr(int *dst, int *src, int size)
{
    int new_size = 0;
    for (int i = 0; i < size; i++)
        if (check_sqr(src[i]))
        {
            if (dst)
                dst[new_size] = src[i];
            new_size++;
        }
    return new_size;
}
