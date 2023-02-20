/*
Слайд 18
*/

#include <stdio.h>

void print(int n, int m, int a[n][m]) // но не void print(int a[n][m], int n, int m) 
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            printf("%d%s", a[i][j], j + 1 < m ? " " : "\n");

    printf("\n");
}

int main(void) 
{
    int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
  
    print(2, 3, a);

    return 0;
}