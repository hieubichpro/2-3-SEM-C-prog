#include "my_funcs.h"

int get_number_by_pos(FILE *f, size_t pos)
{
	int num;
	size_t pos_size;
	pos_size = pos * sizeof(int);
	int rc = fseek(f, pos_size, SEEK_SET);
	if (rc == 0)
		rc = fread(&num, sizeof(int), 1, f);
	return num;
}

void put_number_by_pos(FILE *f, size_t pos, int num)
{
	size_t pos_size = pos * sizeof(int);
	int rc = fseek(f, pos_size, SEEK_SET);
	if (rc == 0)
		rc = fwrite(&num, sizeof(int), 1, f);
}

int create_file(FILE *f, char *str_of_num)
{
	int count;

	char *point = strchr(str_of_num, '.');
	if (point == NULL)
		count = atoi(str_of_num);
	else
		return WRITE_ERR;

	if (count <= 0)
		return WRITE_ERR;

	int i;
	srand(time(NULL));
	for (i = 0; i < count; i++)
	{
		int num = rand() % 100;
		int rc = fwrite(&num, sizeof(int), 1, f);
		if (rc != 1)
			return WRITE_ERR;
	}
	return OK;
}

int file_size(FILE *fsrc, size_t *size)
{
	long size_1;

	if (fseek(fsrc, 0L, SEEK_END))
		return OPEN_ERR;
	size_1 = ftell(fsrc);

	if (size_1 < 0)
		return OPEN_ERR;
	*size = size_1;

	return fseek(fsrc, 0L, SEEK_SET);
}

int print_file(FILE *f)
{
	size_t size_file;
	int rc_read;
	int num;
	int rc = file_size(f, &size_file);
	if (rc != OK)
		return OPEN_ERR;
	if (size_file < sizeof(int))
		return READ_ERR;
	for (size_t i = 0; i < size_file / sizeof(int); i++)
	{
		rc_read = fread(&num, sizeof(int), 1, f);
		if (rc_read == 1)
			printf("%d ", num);
		else
			return READ_ERR;
	}
	return OK;
}

int sort_file(FILE *f)
{
	size_t f_size;
	size_t n;
	int rc = file_size(f, &f_size);
	if (rc == OK)
	{
		if (f_size < sizeof(int))
			return READ_ERR;
		n = f_size / sizeof(int);
		for (size_t i = 0; i < n - 1; i++)
		{
			size_t ind_min = i;
			int curr_min = get_number_by_pos(f, i);
			for (size_t j = i + 1; j < n; j++)
			{
				int curr_num = get_number_by_pos(f, j);
				if (curr_num < curr_min)
				{
					curr_min = curr_num;
					ind_min = j;
				}
			}
			
			int temp1 = get_number_by_pos(f, i);
			int temp2 = get_number_by_pos(f, ind_min);
			put_number_by_pos(f, i, temp2);
			put_number_by_pos(f, ind_min, temp1);
		}
	}
	return OK;
}