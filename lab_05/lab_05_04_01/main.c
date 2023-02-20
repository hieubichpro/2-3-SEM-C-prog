#include "my_funcs.h"

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	int stt;
	// Сортировка по фамилии методом пузырьки
	if (argc == 3 && (strcmp(argv[1], "sb") == 0))
	{
		stt = OK;
		FILE *f = fopen(argv[2], "rb+");
		if (f == NULL)
			return ERROR_IO;

		student student1, student2;
		size_t sz;
		stt = file_size(f, &sz);
		if (stt != 0)
			return ERROR_IO;

		sz /= sizeof(student);
		for (size_t i = 0; i < sz - 1; i++)
			for (size_t j = 0; j < sz - i - 1; j++)
			{
				get_student_by_pos(f, j, &student1);
				get_student_by_pos(f, j + 1, &student2);

				if (strcmp(student1.surname, student2.surname) > 0)
				{
					put_student_by_pos(f, j, &student2);
					put_student_by_pos(f, j + 1, &student1);
				}

				if (strcmp(student1.surname, student2.surname) == 0)
				{
					if (strcmp(student1.name, student2.name) > 0)
					{
						put_student_by_pos(f, j, &student2);
						put_student_by_pos(f, j + 1, &student1);
					}
				}
			}
		fseek(f, 0, SEEK_SET);
		student students[MAX_NUM_ELE];
		int num_stud = from_file_to_array(f, students);
		print_content_in_file(students, num_stud);
		fclose(f);
		return stt;
	}
	// Вывод информации о студентах, фамилии которых начинаются с заданной подстроки, в другой файл
	else if (argc == 5 && (strcmp(argv[1], "fb") == 0))
	{
		stt = OK;
		FILE *f = fopen(argv[2], "rb");
		if (f == NULL)
			return ERROR_IO;

		if (strlen(argv[4]) > MAX_LEN_SUR - 1)
		{
			fclose(f);
			return ERROR_SUBSTR;
		}

		student temp;
		size_t n;
		stt = file_size(f, &n);
		if (stt != 0)
			return ERROR_EMPTY_FILE;
		n /= sizeof(student);

		FILE *f_out = fopen(argv[3], "wb");
		int count = 0;

		for (size_t i = 0; i < n; i++)
		{
			fread(&temp, sizeof(student), 1, f);

			if (strncmp(argv[4], temp.surname, strlen(argv[4])) == 0)
			{
				count += 1;
				fwrite(&temp, sizeof(student), 1, f_out);
			}
		}

		if (count == 0)
			return ERROR_SUBSTR;
		fclose(f);
		fclose(f_out);
		return stt;
	}
	// Удаление из файла студентов, чей средний балл меньше среднего балла по всему файлу
	else if (argc == 3 && (strcmp(argv[1], "db") == 0))
	{
		FILE *f = fopen(argv[2], "rb");

		if (f == NULL)
			return ERROR_IO;
		size_t n;
		stt = file_size(f, &n);
		if (stt != 0)
			return ERROR_EMPTY_FILE;
		n /= sizeof(student);
		student temp;
		double avr = get_avr_all_bin(f, n);

		FILE *f_temp = fopen("temp.bin", "wb");
		int count = 0;
		for (size_t i = 0; i < n; i++)
		{
			fread(&temp, sizeof(student), 1, f);

			if (get_avr(temp.marks) - avr >= EPS || fabs(get_avr(temp.marks) - avr) < EPS)
			{
				fwrite(&temp, sizeof(student), 1, f_temp);
				count ++;
			}
		}
		fclose(f);
		fclose(f_temp);
		f = fopen(argv[2], "wb");
		f_temp = fopen("temp.bin", "rb");

		for (int i = 0; i < count; i++)
		{
			fread(&temp, sizeof(student), 1, f_temp);
			fwrite(&temp, sizeof(student), 1, f);
		}

		fclose(f_temp);

		fseek(f, 0, SEEK_SET);
		student students[MAX_NUM_ELE];
		int num_stud = from_file_to_array(f, students);
		print_content_in_file(students, num_stud);
		fclose(f);
		return stt;
	}
	else
	{
		printf("Error param!");
		return ERROR_PARAM;
	}
	return OK;
}