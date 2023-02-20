#include <stdio.h>
#include "add.h"
#include "func_1.h"

void f_1(void)
{
    int a = 3, b = 2;

    printf("%d + %d = %d\n", a, b, add(a, b));
}