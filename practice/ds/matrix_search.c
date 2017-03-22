#include<stdio.h>
 
/* Searches the element x in mat[][]. If the element is found, 
    then prints its position and returns true, otherwise prints 
    "not found" and returns false */
int search(int mat[4][4], int n, int x)
{
    int i = 0;
    int j = n-1;

    while (i < n && j >=0) {
        if (mat[i][j] == x) {
            printf("%d found at index %d, %d\n", x, i, j);
            return 0;
        } else if (mat[i][j] > x) {
            j--;
        } else {
            i++;
        }
    }
    printf("%d not found\n", x);
    return -1;
}
 
// driver program to test above function
int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  search(mat, 4, 33);
  return 0;
}
