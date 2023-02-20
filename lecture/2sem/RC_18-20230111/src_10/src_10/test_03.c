/*
Слайд 12, часть 2
*/

#define MK_ID(n)	i##n

int main(void)
{
    int MK_ID(1), MK_ID(2), MK_ID(3);

    i1 = 1;
    i2 = 2;
    i3 = 3;

    (void) i1;
    (void) i2;
    (void) i3;

    return 0;
}