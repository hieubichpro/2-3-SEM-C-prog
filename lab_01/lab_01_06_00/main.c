#include<stdio.h>
#include<math.h>
#define EPS 0.000001

int check(double xa, double ya, double xb, double yb, double xc, double yc);

int main(void)
{
	double xa, ya, xb, yb, xc, yc;
	double ab, bc, ac;
	int rc;
	printf("Enter coordinate A, B, C: ");
	rc = scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
	ab = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
	ac = (xc - xa) * (xc - xa) + (yc - ya) * (yc - ya);
	bc = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
	if ((rc == 6) && check(xa, ya, xb, yb, xc, yc))
	{
		if ((ab + ac - bc > EPS) && (ac + bc - ab > EPS) && (bc + ab - ac > EPS))
		{
			printf("0");
			return 0;
		}
		else
		{
			if ((fabs(ab + ac - bc) < EPS) || (fabs(ac + bc - ab) < EPS) || (fabs(bc + ab - ac) < EPS))
			{
				printf("1");
				return 0;
			}
			else
			{
				printf("2");
				return 0;
			}
		}
	}
	else
	{
		printf("Input error");
		return -1;
	}
}

int check(double xa, double ya, double xb, double yb, double xc, double yc)
{
	if (fabs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya)) < EPS)
		return 0;
	return 1; 
}
