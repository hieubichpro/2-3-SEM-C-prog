#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main(void)
{
	double a, b, h;
	double temp, side;
	double p;
	setbuf(stdout, NULL);
	printf("Enter a, b, h: ");
	scanf("%lf %lf %lf", &a, &b, &h);
	temp = pow((b - a) / 2, 2);
	side = sqrt(temp + pow(h, 2));
	p = a + b + 2 * side;
	printf("perimeter: %.6lf", p);
	return 0;	
} 
