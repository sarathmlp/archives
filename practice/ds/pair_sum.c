#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void printPairs(int* arr, int size, int sum)
{
    bool M[MAX] = {0};
    int i;

    for (i=0; i<size; i++) {
        if (sum - arr[i] >= 0 && M[sum - arr[i]]) {
            printf("the pair are %d, %d\n",
                  arr[i], sum - arr[i]);
        }
        M[arr[i]] = 1;
    }
}

/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);

    printPairs(A, arr_size, n);

    return 0;
}
