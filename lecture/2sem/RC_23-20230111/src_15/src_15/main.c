#include <stdio.h>
#include <string.h>
#include "my_malloc.h"

int main(void)
{
    {
        char *pbuf = my_malloc(126);
        
        dump();
        
        strcpy(pbuf, "My name is Igor");
        
        printf("%s\n", pbuf);
        
        my_free(pbuf);
        
        dump();
    }

/*    
    {
        int n_i = 10;
        int *pi = my_malloc(n_i * sizeof(int));
        
        dump();

        for (int i = 0; i < n_i; i++)
            pi[i] = i;
        
        printf("Array: ");
        for (int i = 0; i < n_i; i++)
            printf("%d ", pi[i]);
        printf("\n");
        
        dump();
        
        char *pc = my_malloc(sizeof("I like reading.")); 
        
        strcpy(pc, "I like reading.");
        
        printf("String: %s\n", pc);
        
        dump();

        int n_d = 7;
        double *pd = my_malloc(n_d * sizeof(double));
        
        dump();

        for (int i = 0; i < n_d; i++)
            pd[i] = i * 0.5;
        
        printf("One more array: ");
        for (int i = 0; i < n_d; i++)
            printf("%g ", pd[i]);
        printf("\n");
        
        dump();

        printf("free pc\n");
        my_free(pc);
        
        dump();
        
        printf("free pi\n");
        my_free(pi);
        
        dump();
        
        printf("free pd\n");
        my_free(pd);
        
        dump();
    }
*/

/*
    {
        int n_i = 10;
        int *pi = my_malloc(n_i * sizeof(int));
        
        char *pc = my_malloc(sizeof("My name is Igor. I like reading. I have a cat. ups...")); 

        int n_d = 7;
        double *pd = my_malloc(n_d * sizeof(double));
        
        my_free(pc);
        
        dump();

        char *pc2 = my_malloc(sizeof("I like"));
        
        dump();

        my_free(pi);
        my_free(pd);
        my_free(pc2);
        
        dump();
    }
*/
    
    return 0;
}