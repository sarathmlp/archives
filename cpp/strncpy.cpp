#include <stdio.h>
#include <string.h>

int main()
{
    char buff1[5] = {'h','e','l', 'l', 'o'};
    char buff2[20];
    memset(buff2, 0x60, 20);

    strncpy(buff2, buff1, 19);
    // strncpy(buff2, buff1, 4);

    printf("%s\n", buff2);
    return 0;
}
