#include <stdio.h>

int main(void)
{
	int n, ans;
	printf("Enter money: ");
	scanf("%d", &n);
	if (n < 45)
		printf("0");
	else
	{
		ans = (n - 20) / (45 - 20);
		printf("answer: %d", ans);
	}
	return 0;
}