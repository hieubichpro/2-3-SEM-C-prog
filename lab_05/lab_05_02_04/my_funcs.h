#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERR -1
#define EPS 1e-6
void find_max_min(FILE *f, double *my_min, double *my_max);
int find_ave(FILE *f, double *ave, double my_min, double my_max);
int process(FILE *f, double *ave);
