#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n)
{
    for (int i=0; i < n-1; i++) {

        // Last i elements are already in place 
        for (int j=0; j < n-i-1; j++) {
            if (arr[j+1] < arr[j]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
