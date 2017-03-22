#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define ROW 4
#define COL 5

void findUniqueRows(int M[][COL])
{
    int i;
    int j;
    int k;
    int l;
    bool processed = false;

    for (i=0; i<1; i++) {
        for (j=0; j<COL; j++) {
                printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    for (i=1; i < ROW; i++) {
            processed = false;
        for (j=0; j<i; j++) {
            for(k=0; k<COL; k++) {
                if (M[i][k] != M[j][k])
                    break;

            }
            if (k == COL) {
                processed = true;
                break;
            }
        }

        if (!processed) {
            for (j=0; j<COL; j++) {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
    }
}

// Driver program to test above functions
int main()
{
    // int M[ROW][COL] = {{0, 1, 0, 0, 1},
    //     {1, 0, 1, 1, 0},
    //     {0, 1, 0, 0, 1},
    //     {1, 0, 1, 0, 0}
    // };
 
    int M[ROW][COL] = {{10, 11, 12, 13, 14},
        {10, 11, 12, 13, 13},
        {10, 10, 12, 13, 14},
        {10, 11, 12, 13, 14}
    };
    findUniqueRows( M );
 
    return 0;
}
