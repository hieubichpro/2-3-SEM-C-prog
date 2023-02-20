#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 10
#define OK 0
#define ERR -1
void print(int ans[R], int c)
{
	for (int k = 0; k < c; k++)
	{
		if (k == c - 1)
			printf("%d", ans[k]);
		else
			printf("%d ", ans[k]);
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

void ans_arr(int a[R][C], size_t r, size_t c, int *arr)
{
	for (size_t j = 0; j < c; j++)
	{
		int flag = 1;
		for (size_t i = 0; i < r - 1; i++)
		{
			if (a[i][j] <= a[i + 1][j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && r > 1)
			*(arr + j) = 1;
		else
			*(arr + j) = 0;
	}				
}

int main(void)
{
	int a[R][C];
	int ans[R];
	size_t r, c;
	if (scanf("%zu", &r) != 1 || r < 1 || r > R)
	{
		printf("input error");
		return ERR;
	}
	if (scanf("%zu", &c) != 1 || c < 1 || c > C)
	{
		printf("input error");
		return ERR;
	}
	if (input(a, r, c) == -1)
	{
		printf("input error");
		return ERR;
	}
	ans_arr(a, r, c, ans);
	print(ans, c);
	return OK;
}
