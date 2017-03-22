#include <stdio.h>

int main()
{
    int *ptr = 0x234893249;
    free(ptr);

    return 0;
}
