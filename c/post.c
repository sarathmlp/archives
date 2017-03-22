#include <stdio.h>

int fun(int i)
{
    printf("%d\n", i);
    return i--;
}

int main()
{
    int i = 5;
    i = i++;
    printf("%d\n", fun(++i));
    return 0;
}

