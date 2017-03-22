#include <stdio.h>
#include <string.h>

int fun(char *arr, int len)
{
    if (len < 0)
    {
        printf("\n");
        return 1;
    }
    else
    {
        printf("%c", arr[len]);
        len--;
        fun(arr, len);
    }
}
int main(int argc, char *argv[0])
{
    char arr[20] = "pentagon";
    fun(arr, (strlen(arr)));
    // vosSleep(10);
    // strcpy(argv[0], "MyProgramme");
    // printf("prog name [%s]\n", argv[0]);
    // sleep(10);
    return 0;
}

