#include <stdio.h>
#include <string.h>

int find_sub_str(char str[], char sub[]);

int main()
{
    char str[] = "welcome to new zealand";
    char sub[] = "new";
    int res = 0;

    if ((res = find_sub_str(str, sub)))
        printf("Substring found index %d\n", res);
    else
        printf("Substring not found!\n");

    return 0;
}

int find_sub_str(char str[], char sub[])
{
    int i, j, k;

    for (i = 0; str[i] != '\0'; i++) {
        for (j = i, k = 0; sub[k] != '\0' && str[j] == sub[k]; j++, k++)
            ;
        if (k > 0 && sub[k] == '\0')
            return i;
    }
    return 0;
}
