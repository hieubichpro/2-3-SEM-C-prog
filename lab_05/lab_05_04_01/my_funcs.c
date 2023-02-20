#include "my_funcs.h"

int file_size(FILE *const fsrc, size_t *sz)
{
	long sz_1;
	fseek(fsrc, 0, SEEK_END);
	sz_1 = ftell(fsrc);
	if (sz_1 == 0)
		return ERROR_EMPTY_FILE;
	*sz = sz_1;
	return fseek(fsrc, 0, SEEK_SET);
}

int from_file_to_array(FILE *f, student *students)
{
	student temp;
	int n = 0;
	while (fread(&temp, sizeof(student), 1, f))
	{
		students[n] = temp;
		n += 1;
	}
	if (n == 0)
		return ERROR_EMPTY_FILE;
	return n;
}

void get_student_by_pos(FILE *f, const int pos, student *s)
{
	int cur = 0;
	student temp;

	while (feof(f) == 0)
	{
		fread(&temp, sizeof(student), 1, f);
		
		if (cur == pos)
		{
			*s = temp;
			break;
		}
		cur += 1;
	}
	fseek(f, 0L, SEEK_SET);
}

void put_student_by_pos(FILE *f, const int pos, student *s)
{
	fseek(f, sizeof(student)  *pos, SEEK_SET);
	fwrite(s, sizeof(student), 1, f);
	fseek(f, 0L, SEEK_SET);
}

void print_content_in_file(student *students, const int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", students[i].surname);
		printf("%s\n", students[i].name);

		for (int j = 0; j < NUMBER_OF_MARKS; j++)
			printf("%u ", students[i].marks[j]);
		printf("\n");
	}
}

int remove_student(FILE *const f, size_t num_of_stud, size_t index)
{
	for (size_t i = index; i < num_of_stud - 1; i++)
	{
		student tmp;
		get_student_by_pos(f, i + 1, &tmp);
		put_student_by_pos(f, i, &tmp);
	}
	return 0;
}

double get_avr(unsigned int *s)
{
	unsigned int sum = 0;
	for (int i = 0; i < NUMBER_OF_MARKS; i++)
		sum += s[i];
	return sum / (double)NUMBER_OF_MARKS;
}

double get_avr_all_bin(FILE *f, const int n)
{
	student temp;
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		fread(&temp, sizeof(student), 1, f);
		sum += get_avr(temp.marks);
	}

	fseek(f, 0, SEEK_SET);
	return sum / (double)n;
}