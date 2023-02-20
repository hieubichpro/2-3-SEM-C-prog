/*
Слайд 11, часть 2
*/

#include <stdio.h>

#define N_MAX   10

#define TEST(condition, ...) ((condition) ?        \
         printf("Passed test %s\n", #condition) :  \
                                printf(__VA_ARGS__))

int main(void)
{
    setbuf(stdout, NULL);

    int a = 0, b = 7, n;

    TEST(a == 0, "There is a error (%d)!\n", a);

    TEST(b == 0, "There is a error (%d)!\n", b);

    printf("Enter n: ");
    scanf("%d", &n);

    TEST(n <= N_MAX,
            "n %d exceed %d\n", n, N_MAX);

    return 0;
}
