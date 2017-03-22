#include <stdio.h>

struct nothing {
};


int main()
{
    struct nothing n1;

    printf("%d\n", sizeof(n1));

    return 0;
}
