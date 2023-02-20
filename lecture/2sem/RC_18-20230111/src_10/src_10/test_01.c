/*
Слайд 11, часть 2
*/

#include <stdio.h>

#define PRINT_INT(n) printf(#n " = %d\n", (n))

/*
// Cкобки в данном случае вокруг параметра не нужны!
#define WRONG(n) printf(#(n))
*/

int main(void)
{
    int a = 5, b = 3;

    PRINT_INT(a);

    PRINT_INT(b);

    PRINT_INT(a + b);

    return 0;
}
