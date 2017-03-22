#include <stdio.h>

int linerSearch(int *arr, int size, int x)
{
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == x)
            break;
    }

    if (i == size)
        return -1;

    return i;
}

int main()
{
    int arr[100] = {0};
    int T, size, i, x;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &size);

        for (i=0; i < size; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &x);

        printf("%d\n", linerSearch(arr, size, x));
    }
    return 0;
}
