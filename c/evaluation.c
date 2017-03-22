#include <stdio.h>

int main()
{
    int i = 0;

    printf("%d, %d, %d\n", i++, ++i, i++);
    printf("%d\n", i);

    return 0;
}
