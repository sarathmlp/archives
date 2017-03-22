#include <stdio.h>

int count;
int binarySearch(int* arr, int l, int r, int item) {
    while (l < r) {
        count++;
        // int mid = l+(r-l)/2;
        int mid = l+(r-l) * ((item - arr[l])/(arr[r] - arr[l]));

        if (item == arr[mid]) return mid+1;
        if (item < arr[mid] ) r = mid -1;
        else l = mid+1;
    }
    return -1;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 24, 34, 36, 43, 47, 50, 52, 53, 57, 59, 61, 63, 64, 67, 69, 70, 72, 73, 75, 77, 80, 83, 85, 87, 89, 91, 93, 95, 97, 99};
    int search;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the ele: ");
    scanf("%d", &search);
    int ret = binarySearch(arr, 0, size - 1, search);
    (ret == -1) ? printf("Element not found\n"): printf("Element found at %d\n", ret);
    printf("No of iterations %d\n", count);

    return 0;
}
