#include <stdio.h>
#define N 10
#define OK 0;
#define ERR -1;

int input(int *pb, int *pe);

int main(void)
{
	int a[N];
	int n;
	int temp = -1;
	int *pa = a;
	printf("Enter num of members: ");
	int rc = scanf("%d", &n);
	if (rc != 1 || n < 1 || n > 10)
	{
		printf("Input error");
		return ERR;
	}
	else
	{
		int *pb;
		pb = pa + n;
		int stt = input(pa, pb);
		pb--;
//		printf("*pa = %d, *pb = %d", *pa, *pb);
		if (stt == 0)
		{
			printf("Input error");
			return ERR;
		}
		else
		{
			while (pa <= pb)
			{
				if (temp < (*pa) + (*pb))
					temp = (*pa) + (*pb);
				pa++;
				pb--;
			}
			printf("Result: %d", temp);
		}
	}
	return OK;
}

int input(int *pb, int *pe)
{
	int stt = 1;
	int ele;
	for (; pb < pe;)
	{
		int rc = scanf("%d", &ele);
		if (rc == 1)
		{
			*pb = ele;
			pb++;
		}
		else
		{
			stt = 0;
			break;	
		}
	}
	return stt;
}
