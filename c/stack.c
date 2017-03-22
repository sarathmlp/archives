#include <stdio.h>

struct fish
{
    int i;
};

struct fish* fun(void)
{
    struct fish a;
    return &a;
}

int main()
{
    struct fish *f = fun();
    f->i = 10;
    printf("%d\n", f->i);

    return 0;
}
