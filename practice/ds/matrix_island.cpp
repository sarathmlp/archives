// A C++ program to count the number of rectangular
// islands where every island is separated by a line
#include<iostream>
using namespace std;
 
// Size of given matrix is M X N
#define M 6
#define N 3

int countIslands(int mat[][N])
{
    int count = 0;

    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            if (mat[i][j] == 'X') {
                if ( (i==0 || mat[i-1][j] == 'O') && 
                     (j==0 || mat[i][j-1] == 'O')) {
                    count++;
                }
            }
        }
    }

    return count;
}

// Driver program to test above function
int main()
{
    int mat[M][N] =  {{'O', 'O', 'O'},
                      {'X', 'X', 'O'},
                      {'X', 'X', 'O'},
                      {'O', 'O', 'X'},
                      {'O', 'O', 'X'},
                      {'X', 'X', 'O'}
                    };
    cout << "Number of rectangular islands is "
         << countIslands(mat) << endl;
    return 0;
}
