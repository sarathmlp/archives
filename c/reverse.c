#include <stdio.h>

void reverse(char *str);

int main()
{
    char *str = "hello";
    reverse(str);

    return 0;
}

void reverse (char *str)
{
    if (*str) {
        reverse(str+1);
        printf("%c", *str);
    }
}
