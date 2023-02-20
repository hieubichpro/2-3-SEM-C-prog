/*
Слайд 8, часть 1
*/

#include <stdio.h>

#ifndef NDEBUG
#define DBG_PRINT(s, ...) printf(s, __VA_ARGS__)
#else
#define DBG_PRINT(s, ...) ((void) 0)
#endif

int main(void)
{
    int a = 5, b = 3;
	
    a++;
	
    DBG_PRINT("a = %d\n", a);
	
    b++;
	
    DBG_PRINT("b = %d\n", b);
	
    a = a + b;
	
    DBG_PRINT("a = %d, b = %d\n", a, b);

    return 0;
}
