#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 0
#define GET_PUT_ERR -1
#define WRITE_ERR -2
#define OPEN_ERR -3
#define READ_ERR -4
int get_number_by_pos(FILE *f, size_t pos);
void put_number_by_pos(FILE *f, size_t pos, int num);
int create_file(FILE *f, char *str_of_num);
int file_size(FILE *fsrc, size_t *size);
int print_file(FILE *f);
int sort_file(FILE *f);
