#include <stdio.h>
#include <string.h>

void fun(int arr[])
{
    printf("%lu\n", sizeof(arr)/sizeof(arr[0]));
}

int main()
{
    int arr[10];
    printf("%lu\n", strlen(arr));
    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(arr)/sizeof(arr[0]));

    fun(arr);

    return 0;
}
