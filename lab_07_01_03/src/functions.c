#include "../inc/functions.h"
#include "../inc/filter.h"
#include "../inc/sort.h"

void arr_to_null(arr *a)
{
	a->beg = NULL;
	a->end = NULL;
}

int **get_pb(arr *a)
{
	return &(a->beg);
}

int **get_pe(arr *a)
{
	return &(a->end);
}

size_t get_len(arr *a)
{
	return *get_pe(a) - *get_pb(a);
}

void free_arr(arr *a)
{
	free(*get_pb(a));
	arr_to_null(a);
}

int check_open_file(FILE **f, const char *fname, const char *mode)
{
	int rc = 0;

	*f = fopen(fname, mode);

	if (!(*f))
		rc = OPEN_FILE_ERR;
	
	return rc;
}

int count_num_of_elems(int *cnt, FILE *f)
{
	int rc = OK;
	int number;
	*cnt = 0;

	for (*cnt = 0; fscanf(f, "%d", &number) == 1; (*cnt)++);

	if (*cnt == 0)
		rc = EMPTY_FILE;

	rewind(f);

	return rc;
}

int create_dynamic_array(int **ptr, const int n)
{
	int rc = OK;

	*ptr = malloc(n * sizeof(int));

	if (*ptr == NULL)
		rc = ALLOCATION_ERR;

	return rc;
}

void fill_array(arr *a, FILE *f)
{
	for (int *pt = a->beg; pt < a->end; pt++)
		if (!fscanf(f, "%d", pt))
			return;
}

int get_data(arr *a, FILE *f)
{
	int n;

	int rc = count_num_of_elems(&n, f);

	if (rc)
		return rc;

	rc = create_dynamic_array(get_pb(a), n);

	if (rc)
		return rc;

	*get_pe(a) = *get_pb(a) + n;

	fill_array(a, f);

	return rc;
}

int get_numbers(arr *a, const char *fname)
{
	FILE *f;

	int rc = check_open_file(&f, fname, "r");

	if (rc)
		return rc;
	
	rc = get_data(a, f);

	fclose(f);

	return rc;
}

void write_numbers(arr *a, const char *fname)
{
	FILE *f = fopen(fname, "w");

	for (int *cur = a->beg; cur < a->end; cur++)
		fprintf(f, "%d ", *cur);

	fclose(f);
}


void message_error(const int rc)
{
	switch (rc)
	{
		case ARG_ERR:
			printf("Invalid arguments\n");
			break;
		case READ_FILE_ERR:
			printf("Error data\n");
			break;
		case EMPTY_FILE:
			printf("Empty file\n");
			break;
		case ALLOCATION_ERR:
			printf("Allocate error\n");
			break;
		case POINTER_ERR:
			printf("Err pointer\n");
			break;
		case FILTER_ERR:
			printf("Err filter\n");
			break;
		case OPEN_FILE_ERR:
			printf("Err open file\n");
			break;
		case ARR_ERR:
			printf("Err array\n");
			break;
		default:
			break;
	}
}