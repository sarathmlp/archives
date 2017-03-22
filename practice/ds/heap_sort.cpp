// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 

// Function to swap two integers
void swap(int* x, int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr+i, arr+largest);
        heapify(arr, n, largest);
    }
}

// Function to do heap-sort
void heapSort(int* arr, int n) 
{
    for (int i=(n/2 -1); i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i=n-1; i >=0; i--) {
        swap(arr+0, arr+i);
        heapify(arr, i, 0);
    }
}
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver program
int main()
{
    // int arr[] = {12, 11, 13, 5, 6, 7};
    int arr[] = {3,9,4,1,2,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}
