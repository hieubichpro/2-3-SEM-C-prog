#include<stdio.h>
#include<math.h>
 
int main(void)
{
	double h, t, m;
	double m_normal, bmi;
	printf("Enter h, t, m: ");
	scanf("%lf %lf %lf", &h, &t, &m);
	m_normal = h * t / 240;
	bmi = m / pow(h / 100, 2);
	printf("m_normal, BMI: %.6lf %.6lf", m_normal, bmi);
	return 0;
}
