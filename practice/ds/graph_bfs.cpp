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

    void BFS(int src)
    {
        bool* visited = new bool[V];
        for (int i=0; i<V; i++){
            visited[i] = false;
        }

        list<int> queue;
        visited[src] = true;
        queue.push_back(src);

        list<int>::iterator it;

        while (!queue.empty()) {
            src = queue.front();
            cout << src << " ";
            queue.pop_front();


            for (it = adj[src].begin(); it != adj[src].end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push_back(*it);
                }
            }
        }
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
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
