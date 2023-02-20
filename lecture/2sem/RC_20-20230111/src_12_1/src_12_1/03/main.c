/*
Компиляция выполнится успешно только в том случае, если такое же описание функции add (но без ключевого
слова inline) появится еще где-то в программе (но но здесь!).
*/
#include <stdio.h>

inline int add(int a, int b) {return a + b;}

int main(void)
{
    int i = add(4, 5);
    printf("%d\n", i);
    return i;
}