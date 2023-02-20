#include <stdio.h>

#define N1 1
#define N2 0
#define N3 3
#define N4
#define N5

int main(void)
{
#if N1
    printf("N1\n");
#endif

#if N2
    printf("N2\n");
#endif

#if N3 == 3
    printf("N3\n");
#endif

/*
// test.c:23:7: error: #if with no expression
#if N4
    printf("N4\n");
#endif
*/

#ifdef N5
    printf("N5\n");
#endif


    return 0;
}