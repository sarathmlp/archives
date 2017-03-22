#include <stdio.h>
#define R 3
#define C 6

void spiralPrint(int r_end, int c_end, int arr[][6]) {

    int r_start = 0;
    int c_start = 0;
    int i;

    while (r_start < r_end && c_start < c_end) {
        for (i=c_start; i< c_end; i++) {
            printf("%d ", arr[r_start][i]);
        }
        r_start++;

        for (i=r_start; i<r_end; i++) {
            printf("%d ", arr[i][c_end-1]);
        }
        c_end--;

        if (r_start < r_end) {
            for (i=c_end-1; i >= c_start; i--) {
                printf("%d ", arr[r_end-1][i]);
            }
            r_end--;
        }

        if (c_start < c_end) {
            for (i=r_end-1; i >= r_start; i--) {
                printf("%d ", arr[i][c_start]);
            }
            c_start++;
        }
    }
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    spiralPrint(R, C, a);
    return 0;
}
