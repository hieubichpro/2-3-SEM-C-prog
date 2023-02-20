#include <stdio.h>
#include <math.h>

double power(int a, int n);

int main(void)
{
	int a, n;
	int rc;
	printf("Enter a, n: ");
	rc = scanf("%d %d", &a, &n);
	if ((rc == 2) && (n > 0))
	{
		printf("answer a^n: %.6lf", power(a, n));
		return 0;
	}
	else
	{
		printf("Input error");
		return -1;
	}
}

double power(int a, int n)
{
	int i;
	double ans = 1.0;
	for (i = 0; i < n; i++)
	{
		ans = ans * a;
	}
	return ans;
}
