#include <stdio.h>
#define N 10
#define EMPTY 1
#define OK 0
#define ERR -1

int input(int x[], int *pn);

int main(void)
{
	int a[N];
	int n;
	int ans[N];
	int m = 0;
	int status1 = input(a, &n);
	if (status1 == -1)
		return ERR;
	else
	{
		int sum = 0;
		float ave = 0.0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		ave = sum / n;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > ave)
			{
				ans[m] = a[i];
				m += 1;
			}
		}
		if (m == 0)
		{
			printf("empty massive!");
			return EMPTY;
		}
		else
		{
			printf("new massive: ");
			for (int j = 0; j < m; j++)
				printf("%d ", ans[j]);
		}
	}
	return OK;
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
