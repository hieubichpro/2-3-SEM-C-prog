#include<stdio.h>
#include<math.h>

#define MIN 0.000001

double calc(void);

int main(void)
{
	double g, temp;
	temp = calc();
	if (fabs(temp + 1) <= MIN)
	{
		printf("Error");
		return -1;
	}
	printf("answer g: ");
	g = sqrt(temp);
	printf("%.6lf", g);
	return 0;
}

double calc(void)
{
	double x = 0.0;
	double g = 0.0;
	int n = 0;
	printf("Enter x: ");
	while (x >= -MIN)
	{
		if (scanf("%lf", &x))
		{
			if (x < -MIN)
			{
				if (g < MIN)
					return -1;
				break;
			}
			n = n + 1;
			g = g + x / n;
		}
		else
			return -1;
	}
	return g;
}
