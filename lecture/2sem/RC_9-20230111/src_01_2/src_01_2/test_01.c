/*
Слайд 6
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = NULL;
    size_t n = 5;

    // Выделение памяти
    a = malloc(n * sizeof(int));

    printf("a %p\n", a);

    // Проверка успешности выделения
    if (a == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    // Использование памяти
    size_t i, j;
    for (i = 0; i < n; i++)
        a[i] = i;

    for (j = 0; j < n; j++)
        printf("%d ", a[j]);

    // Освобождение памяти
    free(a);

    return 0;
}