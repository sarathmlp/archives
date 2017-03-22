#include <stdio.h>

enum num {
    one = 0x1,
    two = 0x2
};

int main()
{
    printf("%d\n", one);
    printf("%d\n", two);
    printf("%d\n", two&2);

    return 0;
}
