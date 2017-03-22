#include <stdio.h>

int fact(int num)
{
    if (num > 0)
        return (num * fact(num-1));
    else
        return 1;
}
int main()
{
    int num = fact(3);
    printf("%d\n", num);
    return 0;
}
