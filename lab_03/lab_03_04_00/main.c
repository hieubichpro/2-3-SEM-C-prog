#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 10
#define OK 0
#define ERR -1

int input(int a[R][C], size_t r, size_t c)
{
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return ERR;
	return OK;
}

int find_min(int *min, int a[R][C], int r)
{
	int count = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < i; j++)
			if (a[i][j] % 2)
			{
				*min = a[i][j];
				count++;
			}
	if (count == 0)
		return count;   
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i][j] % 2 && a[i][j] < *min)
				*min = a[i][j];
		}
	}
	return count;
}

int main(void)
{
	int a[R][C];
	int r, c;
	int min;
	if ((scanf("%d", &r)) != 1 || r > 10 || r < 2)
	{
		printf("input error");
		return ERR;
	}
	if ((scanf("%d", &c)) != 1 || c > 10 || c < 2 || r != c)
	{
		printf("input error");
		return ERR;
	}
	if (input(a, r, c) == -1)
	{
		printf("input error");
		return ERR;
	}
	int stt = find_min(&min, a, r);
	if (stt == 0)
	{
		printf("no odd number");
		return ERR;
	}
	printf("%d", min);
	return 0;
}
