/*
Слайд 17
*/

#include <stdio.h>

int main(void)
{
    int n;
	
	setbuf(stdout, NULL);

    printf("n: ");
    scanf("%d", &n);

    int a[n];

    printf("n = %d, sizeof(a) = %d\n", n, (int) sizeof(a));

    for (int i = 0; i < n; i++)
        a[i] = i;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
