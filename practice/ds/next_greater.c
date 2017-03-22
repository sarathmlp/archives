#include <stdio.h>

void printnext(int *arr, int size)
{
    int i, j;
    int nextg;

    for (i=0; i<size; i++) {
        nextg = -1;
        for (j = i+1; j < size; j++) {
            if (arr[j] > arr[i] && nextg == -1) {
                nextg = arr[j];
            }
        }

        printf("%d ", nextg);
    }
}

int main() {
    //code
    int arr[100] = {0};
    int T, size, i, x;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &size);

        for (i=0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        printnext(arr,size);
    }
    return 0;
}
