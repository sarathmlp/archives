#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int i;
    int x = 10;
    int size = sizeof(arr)/sizeof(arr[0]);

    for (i=0; i<size; i++) {
        if (arr[i] == x)
            break;
    }

    if (i == size)
        printf("element not found\n");
    else
        printf("element found at index %d\n", i);

    return 0;
}
