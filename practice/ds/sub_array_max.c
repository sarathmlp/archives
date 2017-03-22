#include <stdio.h>

void print_max(int *arr, int n, int k)
{
    int i, j, x, max;

    for (i=0; i <= n - k; i++) {
        max = 0;
        for (j = i, x = 0; x < k; x++, j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
        }

        printf("%d ", max);
    }
    printf("\n");
}

int main() {
    //code
    int arr[100] = {0};
    int T, n, i, k;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        scanf("%d", &k);

        for (i=0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        print_max(arr, n, k);
    }
    return 0;
}
