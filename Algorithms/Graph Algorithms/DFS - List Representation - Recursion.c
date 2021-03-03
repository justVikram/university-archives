#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node * next;
}NODE;

void initGraph (NODE * Graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        Graph [i].vertex = i;
        Graph [i].next = NULL;
    }
}

void addEdge (NODE * NodeOfGraph, int j)
{
    NODE * NewNode = (NODE *) malloc (sizeof (NODE));
    NewNode->vertex = j;
    NewNode->next = NULL;
    
    if (! NodeOfGraph->next)
        NodeOfGraph->next = NewNode;
    
    else
    {
        NODE * cur = NodeOfGraph;
        
        while (cur->next)
            cur = cur->next;
        
        cur->next = NewNode;
    }
}

void readUnweightedGraph (NODE * Graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int IsEdgePresent;
            printf ("Is there an edge between %d and %d?\n", i, j);
            scanf ("%d", &IsEdgePresent);
            
            if (IsEdgePresent)
            {
                addEdge (&Graph [i], j);  //Add edge between i and j vertices
            }
        }
    }
}
 
void displayGraph (NODE* Graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        NODE * cur = Graph [i].next;
        
        while (cur)
        {
            printf ("Edge between %d and %d\n", i, cur->vertex);
            cur = cur->next;
        }
        
    }
}

void _depthFirstSearch (NODE * Graph, int V, int HeadVertex, int IsVisited [])
{
    printf ("%d\t", HeadVertex);
    IsVisited [HeadVertex] = 1;
    NODE * AdjacentNode = Graph [HeadVertex].next;
    
    while (AdjacentNode)
    {
        int AdjacentVertex = AdjacentNode->vertex;
        
        if (! IsVisited [AdjacentVertex])
            _depthFirstSearch (Graph, V, AdjacentVertex, IsVisited);
        
        AdjacentNode = AdjacentNode->next;
    }
}

void depthFirstSearch (NODE * Graph, int V, int StartVertex)
{
    int IsVisited [10] = {0};
    _depthFirstSearch (Graph, V, StartVertex, IsVisited);
}

int main (int argc, const char * argv[])
{
    int V;
    int StartVertex;
    
    printf ("Enter number of vertices:");
    scanf ("%d", &V);
    
    NODE * Graph = (NODE *) malloc (sizeof (NODE) * V);
    initGraph (Graph, V);
    
    printf ("Enter graph:\n");
    readUnweightedGraph (Graph, V);
    
    printf ("The graph is:\n");
    displayGraph (Graph, V);
    
    printf ("Enter start vertex:");
    scanf ("%d", &StartVertex);
    
    depthFirstSearch (Graph, V, StartVertex);
    return 0;
}
