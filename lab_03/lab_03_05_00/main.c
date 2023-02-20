#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RC 100
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

int input(int a[R][C], int *pr, int *pc)
{
	if (scanf("%d", pr) != 1 || *pr < 1 || *pr > R)
	{
		printf("input error");
		return ERR;
	}
	if (scanf("%d", pc) != 1 || *pc < 1 || *pc > C)
	{
		printf("input error");
		return ERR;
	}	
	for (int i = 0; i < *pr; i++)
		for (int j = 0; j < *pc; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return ERR;
	return OK;
}


int prime(int num)
{
	if (num < 2)
		return 0;
	for (int i = 2; i < num; i++)
		if ((num % i) == 0)
			return 0;
	return 1;
}

int arr_prime(int a[R][C], int r, int c, int arr_prime[RC], int *rc)
{
	int cnt = 0;
	int flag = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (prime(a[i][j]) == 1)
			{
				arr_prime[cnt] = a[i][j];
				cnt += 1;
				flag = 1;
			}
	*rc = cnt;
	if (flag == 1)
		return 1;
	else
		return 0;
}

int arr_reverse(int arr_prime[RC], int rc)
{
	int i = 0;
	int j = rc - 1;
	while (i < j)
	{
		int temp = arr_prime[i];
		arr_prime[i] = arr_prime[j];
		arr_prime[j] = temp;
		i ++;
		j --;
	}
	return 0;
}

int write_matrix(int a[R][C], int r, int c, int arr_rev[RC])
{
	int cnt = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (prime(a[i][j]))
			{
				a[i][j] = arr_rev[cnt];
				cnt += 1;
			}
	return 0;
}

int main(void)
{
	int a[R][C];
	int r, c;
	int temp[RC];
	int rc = 0;
	if (input(a, &r, &c) != 0)
		return ERR;
	int stt = arr_prime(a, r, c, temp, &rc);
	if (stt == 0)
	{
		printf("prime_num no found");
		return ERR;
	}
	arr_reverse(temp, rc);
	write_matrix(a, r, c, temp);
	print(a, r, c);
	return 0;
}
