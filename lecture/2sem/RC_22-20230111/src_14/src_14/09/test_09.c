/*
Последовательность вычислений операндов
*/

#include <stdio.h>

int f1(void)
{
    printf("f1\n");
    return 1;
}

int f2(void)
{
    printf("f2\n");
    return 1;
}

void f3(int a, int b)
{
    ;
}

int a(void)
{
    printf("a\n");
    return 1;
}

int b(void)
{
    printf("b\n");
    return 1;
}

int c(int n)
{
    printf("c\n");
    return n;
}

int d(int m)
{
    printf("d\n");
    return m;
}

int main()
{
    int p1, p2, p3, p4, p6, p7, p8;
    int x[3] = {0}, i = 1;

    p1 = f1() + f2();
    printf("\n");

    p2 = f1() - f2(); 
    printf("\n");

    p3 = f1() * f2(); 
    printf("\n");

    p4 = f1() / f2(); 
    printf("\n");

    f3(f1(), f2());
    printf("\n");

    f3(c(a()), d(b()));
    printf("\n");

    x[i] = i++ + 1;
    printf("%d %d %d\n\n", x[0], x[1], x[2]);

    p6 = f1() && f2();
    printf("\n");
  
    // p7 = (f1(), f2());
    // printf("\n"); ????

    p8 = f1() ? f2(): 3;
    printf("\n");

    return 0;
}
