/*
Слайд 12, часть 2
*/

#include <stdio.h>

#define GENERAL_MAX(type)         \
type type##_max(type x, type y)   \
{                                 \
    return x > y ? x : y;         \
}

GENERAL_MAX(int)

GENERAL_MAX(float)

int main(void)
{
    int a = 5, b = 10;
    float c = 2.5, d = 0.5;

    printf("Max from %d and %d is %d\n", a, b, int_max(a, b));

    printf("Max from %.2f and %.2f is %.2f\n", c, d, float_max(c, d));

    return 0;
}