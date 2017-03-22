#include <stdio.h>

void fun(int *arr);

int main()
{
    int arr[5] = {1,2,3,4,5};
    printf("%lu\n", sizeof(arr));
    int i;

    fun (arr);

    for (i=0; i<5; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}

void fun(int *arr)
{
    int i;
    for (i=0; i<5; i++) {
        printf("%d", arr[i]);
        arr[i] += 1;
    }
    printf("\n");
}
