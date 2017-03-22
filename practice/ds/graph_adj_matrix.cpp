/*
 * C++ Program to Implement Adjacency Matrix
 */
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
/*
 * Adjacency Matrix Class
 */
class AdjacencyMatrix
{
private:
    int n;
    int **adj;

public:
    AdjacencyMatrix(int n)
    {
        this->n = n;
        adj = new int* [n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int [n];
            for(int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    /*
     * Adding Edge to Graph
     */ 
    void add_edge(int origin, int destin)
    {
        if( origin > n || destin > n || origin < 0 || destin < 0)
        {   
            cout<<"Invalid edge!\n";
        }
        else
        {
            // di-graph
            adj[origin - 1][destin - 1] = 1;
            // adj[destin - 1][origin - 1] = 1;
        }
    }
    /*
     * Print the graph
     */ 
    void display()
    {
        int i,j;
        for(i = 0;i < n;i++)
        {
            for(j = 0; j < n; j++)
                cout<<adj[i][j]<<"  ";
            cout<<endl;
        }
    }
};
/*
 * Main
 */ 
int main()
{
    AdjacencyMatrix am(5);

    am.add_edge(1, 2);
    am.add_edge(1, 4);
    am.add_edge(1, 5);
    am.add_edge(2, 3);
    am.add_edge(2, 5);
    am.add_edge(3, 1);
    am.add_edge(5, 2);
    am.add_edge(4, 3);

    am.display();
    return 0;
}

