#include <stdio.h>
#include "add.h"
#include "func_2.h"

void f_2(void)
{
    int a = 7, b = -2;

    printf("%d + %d = %d\n", a, b, add(a, b));
}