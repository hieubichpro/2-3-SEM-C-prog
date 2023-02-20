#include <stdio.h>
#define N 10
#define OK 0
#define ERR -1

int input(int x[], int *pn);
int is_palin(int num);
void rm_palin(int x[], int *pn, int pos);

int main(void)
{
	int a[N];
	int n;
	int status1 = input(a, &n);
	if (status1 == -1)
	{
		printf("Input error");
		return ERR;
	}
	else
	{
		int i = 0;
		while (i < n)
		{
			int status2 = is_palin(a[i]);
			if (status2 == 1)
			{
				rm_palin(a, &n, i);
				i -= 1;
			}
			i += 1;
		}
		if (n == 0)
		{
			printf("empty massive");
			return ERR;
		}
		else
		{
			printf("massive after remove: ");
			for (int i = 0; i < n; i++)
				printf("%d ", a[i]);
		}
	}
	return OK;
}

int input(int x[], int *pn)
{
	printf("Enter num of member: ");
	if (scanf("%d", pn) != 1 || *pn < 1 || *pn > N)
		return ERR;
	else
	{
		for (int i = 0; i < *pn; i++)
		{
			if (scanf("%d", &x[i]) != 1)
				return ERR;
		}
	}
	return OK;
}

int is_palin(int num)
{
	int cp_num = num;
	int digit;
	int rev = 0;
	while (num > 0)
	{
		digit = num % 10;
		num = num / 10;
		rev = rev * 10 + digit;
	}
	if (rev == cp_num)
		return 1;
	else
		return 0;
}

void rm_palin(int x[], int *pn, int pos)
{
	for (int i = pos; i < *pn - 1; i++)
		x[i] = x[i + 1];
	*pn -= 1;
}
