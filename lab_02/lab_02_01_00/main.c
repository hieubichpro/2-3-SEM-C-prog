#include <stdio.h>
#define N 10
#define EMPTY -100
#define OK 0
#define ERR -1

int input(int x[], int *pn);
int sum(int x[], int n);

int main(void)
{
	int a[N];
	int n;
	int status1 = input(a, &n);
	if (status1 == -1)
		return ERR;
	else
	{
		int status2 = sum(a, n);
		if (status2 == -100)
		{
			printf("no even number in massive!");
			return EMPTY;
		}
		else
			printf("sum of even numbers: %d", sum(a, n));
		return OK;
	}
}

int input(int x[], int *pn)
{
	printf("Enter num of member: ");
	if (scanf("%d", pn) != 1 || *pn < 1 || *pn > N)
	{
		printf("Input error");
		return ERR;
	}
	else
	{
		for (int i = 0; i < *pn; i++)
		{
			if (scanf("%d", &x[i]) != 1)
			{
				printf("Input error");
				return ERR;
			}
		}
	}
	return OK;
}

int sum(int x[], int n)
{
	int s = 0;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] % 2 == 0)
		{
			s += x[i];
			flag = 1;
		}
	}
	if (flag == 1)
		return s;
	else
		return EMPTY;
}