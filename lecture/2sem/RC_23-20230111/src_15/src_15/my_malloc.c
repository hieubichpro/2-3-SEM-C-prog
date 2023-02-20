#include <assert.h>
#include <stdio.h>
#include "my_malloc.h"


#define MY_HEAP_SIZE 1000000


struct block_t
{
    size_t size;
    int free;
    struct block_t *next; 
};


static char my_heap[MY_HEAP_SIZE];


static struct block_t *free_list = (struct block_t*) my_heap;


static void initialize(void)
{
    free_list->size = sizeof(my_heap) - sizeof(struct block_t);
    free_list->free = 1;
    free_list->next = NULL;
}


static void split_block(struct block_t *block, size_t size)
{
    size_t rest = block->size - size;
    
    if (rest > sizeof(struct block_t))
    {
        struct block_t *new = (void*)((char*) block + size + sizeof(struct block_t));
    
        new->size = block->size - size - sizeof(struct block_t);
        new->free = 1;
        new->next = block->next;
    
        block->size = size;
        block->free = 0;
        block->next = new;
    }
    else
        block->free = 0;
}


static void merge_blocks(void)
{
    struct block_t *cur = free_list;
    
    while (cur && cur->next != NULL)
    {
        if (cur->free && cur->next->free)
        {
            cur->size += cur->next->size + sizeof(struct block_t);
            cur->next = cur->next->next;
        }
        else
            cur = cur->next;
    }
}


// static void initialize(void)
// {
//     free_list->size = sizeof(my_heap) - sizeof(struct block_t);
//     free_list->free = 1;
//     free_list->next = NULL;
// }

void* my_malloc(size_t size)
{
    struct block_t *cur;
    void *result;

    if (!free_list->size)
    {
        initialize();
    }
    
    cur = free_list;
    while (cur && (cur->free == 0 || cur->size < size))
        cur = cur->next;

    if (!cur)
    {
        result = NULL;
        
        printf("Out of memory\n");
    }
    else if (cur->size == size)
    {
        cur->free = 0;
        result = (void*) (++cur);
    }
    else
    {
        split_block(cur, size);
        
        result = (void*) (++cur);
    }
        
    return result;
}


void my_free(void *ptr)
{
    if (my_heap <= (char*) ptr && (char*) ptr <= my_heap + sizeof(my_heap))
    {
        struct block_t *cur = ptr;
        
        --cur;
        cur->free = 1;
        
        merge_blocks();
    }
    else
        printf("Wrong pointer\n");
}


void dump(void)
{
    struct block_t *cur = free_list;

    printf("\ndump heap:\n");
    
    printf("sizeof(block_t) %u\n\n", (unsigned) sizeof(struct block_t));
    
    while (cur)
    {
        printf("Data %p, size %u, free %d\n", (void*) (cur + 1), (unsigned) cur->size, cur->free);
        cur = cur->next;
    }
    printf("\n");
}
