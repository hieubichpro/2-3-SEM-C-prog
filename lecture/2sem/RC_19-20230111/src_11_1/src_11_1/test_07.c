/*
Слайд 20
*/

// Для компиляции в MSYS2 нужно использовать подсистему msys (POSIX)
#include <alloca.h>
#include <stdio.h>

int main(void)
{
    int n;
	
	setbuf(stdout, NULL);

    printf("n: ");
    scanf("%d", &n);

    int *a = alloca(n * sizeof(int));

    for (int i = 0; i < n; i++)
        a[i] = i;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
