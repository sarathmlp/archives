#include <stdio.h>

int main()
{
    int x = 3;
    int y;

    if ( (y = x) == 3)
        printf("Correct\n");
    else
        printf("Not Correct\n");

    return 0;
}
