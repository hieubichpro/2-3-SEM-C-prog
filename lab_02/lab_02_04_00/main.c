#include <stdio.h>
#define N 10
#define OVERFLOW 100
#define OK 0
#define ERR -1

int input(int x[], int *pn);
void bbsort(int x[], int n);
int main(void)
{
	int a[N];
	int n = 0;
	int status_io = input(a, &n);
	if (status_io == -1)
	{
		printf("Input error");
		return ERR;
	}
	else
	{
		bbsort(a, n);
		printf("after ");
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		if (status_io == 1)
			return OVERFLOW;
		return OK;
	}
}

int input(int x[], int *pn)
{
	int flag = 1;
	int overflow = 0;
	printf("Enter members of massive: ");
	while (flag == 1)
	{
		int status = scanf("%d", &x[*pn]);
		if (status != 1)
			break;
		*pn += 1;
		if (*pn > 10)
		{
			*pn = 10;
			overflow = 1;
			break;
		}
	}
	if (*pn == 0)
		return ERR;
	return overflow;
}

void bbsort(int x[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (x[j] > x[j + 1])
			{
				int temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}
