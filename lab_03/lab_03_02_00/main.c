#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 10
#define OK 0
#define ERR -1

void print(int a[R][C], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (j == c - 1)
				printf("%d", a[i][j]);
			else
				printf("%d ", a[i][j]);
		}
		if (i != r - 1)
			printf("\n");
	}		
}

int input(int a[R][C], size_t r, size_t c)
{
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return ERR;
	return OK;
}

int check(int a[R][C], int i, int c, int digit)
{
	int end = 0, start = 0, temp1, temp2;
	for (int j = 0; j < c; j++)
	{
		if (a[i][j] < 0)
		{
			temp1 = -a[i][j];
			temp2 = -a[i][j];
		}
		else
		{
			temp1 = a[i][j];
			temp2 = a[i][j];
		}
		if (temp1 % 10 == digit)
			end += 1;
		while (temp2 > 9)
			temp2 /= 10;
		if (temp2 == digit)
			start += 1;
	}
	if (end != 0 && start != 0 && end == start)
		return 1;
	else
		return 0;
}

void insert(int a[R][C], int *r, int c, int pos)
{
	*r += 1;
	pos += 1;
	int i = *r - 1;
	while (i > pos)
	{
		for (int j = 0; j < c; j++)
			a[i][j] = a[i - 1][j];
		i--;
	}
	for (int j = 0; j < c; j++)
		a[pos][j] = 100;
}

int main(void)
{
	int a[R][C];
	int r, c;
	int digit;
	if (scanf("%d", &r) != 1 || r < 1 || r > R)
	{
		printf("input error");
		return ERR;
	}
	if (scanf("%d", &c) != 1 || c < 1 || c > C)
	{
		printf("input error");
		return ERR;
	}
	if (input(a, r, c) == -1)
	{
		printf("input error");
		return ERR;
	}
	if (scanf("%d", &digit) != 1 || digit < 0 || digit > 9)
	{
		printf("input error");
		return ERR;
	}
	int i = 0;
	while (i < r)
	{
		int stt = check(a, i, c, digit);
		if (stt == 1)
		{
			insert(a, &r, c, i);
			i += 1;
		}
		i += 1;
	}
	print(a, r, c);
	return 0;
}
