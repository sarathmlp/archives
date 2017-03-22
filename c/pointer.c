#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_fun(char** ptr)
{
    char* local_ptr = *ptr;
    printf("%s\n", local_ptr);

    *ptr = NULL;
    // strcpy(*ptr, "fish");
    printf("%s\n", local_ptr);
}

int main()
{
    char *str = malloc (10);
    strcpy(str, "hello");
    printf("%s\n", str);

    str_fun(&str);
    printf("%s\n", str);

    return 0;
}
