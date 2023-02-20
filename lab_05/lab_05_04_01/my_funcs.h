#include <stdio.h>
#include <string.h>
#include <math.h>

#define OK 0
#define ERROR_IO -1
#define ERROR_OPEN -2
#define ERROR_EMPTY_FILE -3
#define ERROR_SUBSTR -4
#define ERROR_DATA_FILE -5
#define ERROR_PARAM 53

#define MAX_LEN_SUR 26
#define MAX_LEN_NAME 11
#define MAX_NUM_ELE 100
#define NUMBER_OF_MARKS 4
#define EPS 1e-6

typedef struct
{
	char surname[MAX_LEN_SUR];
	char name[MAX_LEN_NAME];
	unsigned int marks[NUMBER_OF_MARKS];
} student;

int file_size(FILE *const fsrc, size_t *sz);
int from_file_to_array(FILE *f, student *students);
void print_content_in_file(student *students, const int n);
void get_student_by_pos(FILE *f, const int pos, student *s);
void put_student_by_pos(FILE *f, const int pos, student *s);
double get_avr_all_bin(FILE *f, const int n);
double get_avr(unsigned int *s);
int remove_student(FILE *const f, size_t num_of_stud, size_t index);