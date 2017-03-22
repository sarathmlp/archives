#include <stdio.h>
#define SZ 10

void print(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, n);
    }
}

void heapsort(int arr[], int n)
{
    int i;
    for (i=n/2 -1; i >= 0; i--)
        heapify(arr, i, n);

    for (int i=n-1; i >= 0; i--) {
        swap(arr+0, arr+i);
        heapify(arr, 0, i);
    }
}

int main()
{
    int arr[] = {3,9,4,1,2,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr, n);

    heapsort(arr, n);

    print(arr, n);

    return 0;
}
