#include "my_funcs.h"

int main(int argc, char **argv)
{
	if ((strcmp(argv[1], "c") == 0) && argc == 4)
	{
		FILE *f;
		f = fopen(argv[3], "wb");
		int rc = create_file(f, argv[2]);
		if (rc != 0)
			return -1;
		fclose(f);
	}
	else if (strcmp(argv[1], "p") == 0 && argc == 3)
	{
		FILE *f;
		f = fopen(argv[2], "rb");
		int rc = print_file(f);
		if (rc != 0)
			return -1;
		fclose(f);
	}
	else if (strcmp(argv[1], "s") == 0 && argc == 3)
	{
		FILE *f;
		f = fopen(argv[2], "r+b");
		int rc = sort_file(f);
		if (rc != 0)
			return -1;
		fclose(f);
	}
	else
	{
		printf("not enough arguments\n");
		return -1;
	}
	return OK;
}