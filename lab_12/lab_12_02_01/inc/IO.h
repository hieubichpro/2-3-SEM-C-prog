#ifndef __IO_H__
#define __IO_H__

#include "error.h"
#include "sort.h"

int check_file_io(FILE **f_in, char *fname, char *mode);
// int check_file_out(FILE **f_out, char *fname);

int count_elements(int *count, int end_file, FILE *f_in);
int memory_allocate(int **pb_src, int len);
void memory_deallocate(int **pb_src);
int read_number(int *pos, FILE *f);
int read_numbers(int *pb_src, int *pe_src, FILE *f);
int process_read_numbers_from_file(int **pb_src, int **pe_src, char *fname);

int write_number(FILE *f, int number);
int write_numbers(FILE *f, int *pb_src, int *pe_src);
int process_write_numbers_to_file(char *fname, int *pb_src, int *pe_src);
#endif