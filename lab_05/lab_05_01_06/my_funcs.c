#include "my_funcs.h"

int process(FILE *f, int *cnt_max)
{
	*cnt_max = 1;
	int cnt = 1;
	int st = 0;
	int incr = 1, decr = 1;
	int num;
	int buf;
	while (fscanf(f, "%d", &num) == 1)
	{
		st ++;
		if (st == 1)
			buf = num;
		if (num > buf && incr)
		{
			decr = 0;
			buf = num;
			cnt ++;
		}
		else if (num < buf && decr)
		{
			incr = 0;
			buf = num;
			cnt ++;
		}
		else
		{
			incr = 0;
			decr = 0;
			if (num > buf)
			{
				cnt = 2;
				incr = 1;
			}
			else if (num < buf)
			{
				cnt = 2;
				decr = 1;
			}
			else
			{
				cnt = 1;
				incr = 1;
				decr = 1;
			}
			buf = num;
		}
		if (cnt > *cnt_max)
			*cnt_max = cnt;
	}
	if (st == 0 || st == 1)
		return ERR;
	if (*cnt_max == 1)
		*cnt_max = 0;
	return OK;
}