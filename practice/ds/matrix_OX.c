#include <stdio.h>
#define R 6
#define C 7

void spiralPrint(int r_end, int c_end, int arr[][C]) {

    int r_start = 0;
    int c_start = 0;
    int i;

    char c = 'X';

    while (r_start < r_end && c_start < c_end) {
        for (i=c_start; i< c_end; i++) {
            arr[r_start][i] = c;
        }
        r_start++;

        for (i=r_start; i<r_end; i++) {
            arr[i][c_end-1] = c;
        }
        c_end--;

        if (r_start < r_end) {
            for (i=c_end-1; i >= c_start; i--) {
                arr[r_end-1][i] = c;
            }
            r_end--;
        }

        if (c_start < c_end) {
            for (i=r_end-1; i >= r_start; i--) {
                arr[i][c_start] = c;
            }
            c_start++;
        }

        c = (c == 'X')? 'O' : 'X';
    }

    // Print the filled matrix
    for (i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }
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
