#include "my_funcs.h"

int process(FILE *f, double *ave)
{
	double my_max = -1000.0;
	double my_min = 10000.0;
	find_max_min(f, &my_min, &my_max);
	fseek(f, 0L, SEEK_SET);
	int rc = find_ave(f, ave, my_min, my_max);
	if (rc != OK)
		return ERR;
	return OK;
}

void find_max_min(FILE *f, double *my_min, double *my_max)
{
	double num;
	while (fscanf(f, "%lf", &num) == 1)
	{
		if (num > *my_max)
			*my_max = num;
		if (num < *my_min)
			*my_min = num;
	}
}

int find_ave(FILE *f, double *ave, double my_min, double my_max)
{
	double sum = 0.0;
	int cnt = 0;
	int run = 0;
	double num;
	while (fscanf(f, "%lf", &num) == 1)
	{
		if (fabs(num - my_min) < EPS || fabs(num - my_max) < EPS)
		{
			run ++;
			continue;
		}
		if (run > 2)
			return -1;
		if (run == 1)
		{
			sum += num;
			cnt ++;
		}
	}
	if (cnt == 0)
		return ERR;
	if (run != 2)
		return ERR;
	*ave = sum / (double)cnt;
	return OK;
}
