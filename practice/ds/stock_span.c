#include <stdio.h>
#include <string.h>

void print_span(int *arr, int size, int *span)
{
    int i, j;

    for (i=0; i < size; i++) {
        span[i] =1;
        for (j=0; j<i; j++) {
            if (arr[j] < arr[i])
                span[i]++;
        }
    }

    for (i=0; i<size; i++) {
        printf("%d ", span[i]);
        span[i] = 0;
    }
}

int main()
{
    int arr[100] = {0};
    int span[100] = {0};
    int T, size, i, x;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &size);

        for (i=0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        print_span(arr,size,span);
        printf("\n");
    }
    return 0;
}
