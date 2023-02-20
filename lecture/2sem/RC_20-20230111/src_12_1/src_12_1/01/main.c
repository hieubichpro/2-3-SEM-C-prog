/*
Компиляция выполнится успешно (у функции add внутренне связывание).
*/

static inline int add(int a, int b) {return a + b;}

int main(void)
{
    int i = add(4, 5);

    return i;
}