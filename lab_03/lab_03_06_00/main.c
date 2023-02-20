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

void fill_matrix(int a[R][C], int r, int c)
{
	int r_c = r * c;
	int i = 0, j = 0, n = 1;
	while (n <= r_c)
	{
		while (i < r)
		{
			a[i][j] = n;
			n += 1;
			i += 1;
		}
		i -= 1;
		j += 1;
		while (i >= 0)
		{
			a[i][j] = n;
			n += 1;
			i -= 1;
		}
		j += 1;
		i += 1;
	}
}

int read_rc(int *pr, int *pc)
{
	if (scanf("%d", pr) != 1 || *pr < 1 || *pr > 10)
	{
		printf("input error");
		return ERR;
	}
	if (scanf("%d", pc) != 1 || *pc < 1 || *pc > 10)
	{
		printf("input error");
		return ERR;
	}
	return OK;
}

int main(void)
{
	int a[R][C];
	int r, c;
	if (read_rc(&r, &c) != 0)
		return ERR;
	fill_matrix(a, r, c);
	print(a, r, c);
}
