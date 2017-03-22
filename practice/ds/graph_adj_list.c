// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int dst;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct Graph* createGraph(int V)
{
    struct Graph* graph= (struct Graph*) malloc (sizeof(struct Graph));
    graph->array = (struct AdjList*) malloc (V * sizeof(struct AdjList));
    graph->V = V;

    int i;
    for (i=0; i<V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

struct AdjListNode* createNode(int dst)
{
    struct AdjListNode* nn = 
        (struct AdjListNode*) malloc (sizeof(struct AdjListNode));

    nn->dst = dst;
    nn->next = NULL;
    return nn;
}

void addEdge(struct Graph* graph, int src, int dst) 
{
    struct AdjListNode* newNode = createNode(dst);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    /* since it's undirected graph */
    newNode = createNode(src);
    newNode->next = graph->array[dst].head;
    graph->array[dst].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int i;
    for (i=0; i<graph->V; i++) {
        struct AdjListNode* ptr = 
            graph->array[i].head;

        printf("Adjacent nodes of %d :", i);
        while (ptr) {
            printf("%d ", ptr->dst);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}
