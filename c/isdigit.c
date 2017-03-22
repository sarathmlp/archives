#include <stdio.h>
#include <ctype.h>

int main()
{
    char arr[] = "ab1c23de5";
    int i;

    for (i=0; i < strlen(arr); i++)
    {
        if (isdigit(arr[i]))
        {
            printf("Digit %d\n", arr[i] - '0');
        }
        else if (isalpha(arr[i]))
        {
            printf("Alpha %c\n", arr[i]);
        }
    }

    return 0;
}
