#ifndef _FILTER_H_
#define _FILTER_H_

int get_new_size(const int *pb_src, const int *pe_src);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif