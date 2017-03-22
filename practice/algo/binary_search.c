#include <stdio.h>

int binary_search(int arr[], int n, int el)
{
    int mid;
    int left = 0;
    int right = n - 1;


    while (left <= right) {
        // mid = (right + left)/2;
        mid = left + (right - left)/2;

        if (el == arr[mid])
            return mid;
        else if (el < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = binary_search(arr, size, 9);

    if (res == -1)
        printf("element not found\n");
    else
        printf("element found at index %d\n", res);

    return 0;
}
