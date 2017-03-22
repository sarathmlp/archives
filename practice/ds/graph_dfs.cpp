// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
private:
    int V;
    list<int>* adj;

public:
    Graph(int v)
    {
        V = v;
        adj = new list<int>[V];
    }

    void addEdge(int src, int dst)
    {
        adj[src].push_back(dst);
    }

    void BFSUtil(int src, bool* visited) 
    {
        cout << src << " ";
        visited[src] = true;
        list<int>::iterator it;

        for (it = adj[src].begin(); it != adj[src].end(); it++) {
            if (!visited[*it]) {
                BFSUtil(*it, visited);
            }

        }
    }

    void BFS(int src)
    {
        bool* visited = new bool[V];
        for (int i=0; i<V; i++){
            visited[i] = false;
        }

        BFSUtil(src, visited);
    }
};

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
