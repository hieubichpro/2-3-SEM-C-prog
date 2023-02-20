#include<stdio.h>
#include<math.h>

double calc(double x, double eps);

int main(void)
{
	double x, eps;
	double delta, teta, sx, fx;
	printf("Enter x, eps: ");
	if (scanf("%lf", &x) != 1)
		return -1;
	if (scanf("%lf", &eps) != 1)
		return -1;
	if (eps <= 0 || eps > 1)
		return -1;
	sx = calc(x, eps);
	fx = exp(x);
	delta = fabs(sx - fx);
	teta = fabs(fx - sx) / fabs(fx);
	printf("%.6lf %.6lf %.6lf %.6lf", sx, fx, delta, teta);
	return 0;
}

double calc(double x, double eps)
{
	double s = 1.0;
	int n = 1;
	double operand = 1.0;
	while (fabs(operand) >= eps)
	{
		operand = (operand * x) / n;
		s = s + operand;
		n = n + 1;
	}
	return s;	
}
