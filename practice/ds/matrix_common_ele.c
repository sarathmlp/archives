// A C program to find a common element in all rows of a
// row wise sorted array
#include<stdio.h>
 
// Specify number of rows and columns
#define M 4
#define N 5

void findCommon(int mat[][5]) 
{
    int i;
    int j;
    int arr[1000] = {0}; // max val of elem

    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            if (arr[mat[i][j]] == i) {
                arr[mat[i][j]]++;
                if (i==M-1) {
                    printf("%d\n", mat[i][j]);
                }
            }
        }
    }
}

// driver program to test above function
int main()
{
  int mat[M][N] = { {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };

  //   int mat[M][N] =
  //   {
  //       {1, 2, 1, 4, 8},
  //       {3, 7, 8, 5, 1},
  //       {8, 7, 7, 3, 1},
  //       {8, 1, 2, 7, 9},
  //   };
  findCommon(mat);
  return 0;
}
