#include "../inc/sort.h"

int cmp(float value, object_t *second)
{
    return value < second->macca / second->volumn;
}

void my_insert_sort(object_t *obj_arr, int len)
{
    for (int i = 1, j; i < len; i++)
    {
        object_t buffer = *(obj_arr + i);
        j = i - 1;
        float value = (obj_arr + i)->macca / (obj_arr + i)->volumn;
        while (j >= 0 && cmp(value, obj_arr + j))
        {
            *(obj_arr + j + 1) = *(obj_arr + j);
            j--;
        }
        *(obj_arr + j + 1) = buffer;
    }
}