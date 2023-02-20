#include<stdio.h>

void turn_to_the_right(unsigned int a, int n);

int main(void)
{
	unsigned int a;
	int n;
	int rc;
	printf("Enter a, n: ");
	rc = scanf("%u %d", &a, &n);
	if ((rc == 2) && (n >= 0))
	{
		printf("Result: ");
		turn_to_the_right(a, n);
		return 0;
	}
	else
	{
		printf("Error: Input error");	
		return -1;
	}
}

void turn_to_the_right(unsigned int a, int n)
{
	int x;
	n = n % 32;
	for (x = n - 1; x > -1; x--)
		printf("%d", (a >> x) & 1);
		
	for (x = 31; x >= n; x--)
		printf("%d", (a >> x) & 1);    
}
