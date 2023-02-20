/*
К слайду 12, часть 2
*/

struct point
{
    int *x;
    int *y;
    int n;
};


#define MAKE_POINT(name, N)                  \
int          name##_x[N];                    \
int          name##_y[N];                    \
struct point name = {name##_x, name##_y, N}


int main(void)
{
    MAKE_POINT(a, 3);
    MAKE_POINT(b, 3);
}