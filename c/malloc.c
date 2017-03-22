#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    p = (int*) malloc(64);
    free(p);
    return 0;
}
