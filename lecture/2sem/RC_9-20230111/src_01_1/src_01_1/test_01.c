/*
Слайд 2
*/

#include <stdio.h>

int main(void)
{
    double d = 5.0;
    double *pd = &d;
    void *pv = pd;
    pd = pv;
    int *pi = pv;
    int num = 10;
    void *t = &num;
    pd = t;
    printf("%d\n", *pd);
    printf("%d\n", num);
    printf("%lf\n", num);
    printf("%lf\n", *pd);
    /*
    // error: dereferencing 'void *' pointer
    // error: invalid use of void expression
    printf("%d\n", *pv);
    */

    /*
    // error: dereferencing 'void *' pointer
    pv++;
    */

    return 0;
}