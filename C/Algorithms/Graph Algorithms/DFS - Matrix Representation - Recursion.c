
#include <stdio.h>
#include <stdlib.h>

//Recursive

void readUnweightedUndirectedGraph (int Graph [][10], int V)
{
    int IsEdgePresent;
    int j  = 0;
    
    for (int i = 0; i < V; i++)
    {
        for (j = i; j < V; j++)
        {
            printf ("Is there an edge from %d to %d? [0 | 1]\n", i, j);
            scanf ("%d", &IsEdgePresent);
            
            if (IsEdgePresent)
                Graph [i][j] = Graph [j][i] = 1;
            
            else if (! IsEdgePresent)
                Graph [i][j] = Graph [j][i] = 0;
        }
    }
}

void readUnweightedDirectedGraph (int Graph [][10], int V)
{
    int IsEdgePresent;
    int j  = 0;
    
    for (int i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf ("Is there an edge from %d to %d? [0 | 1]\n", i, j);
            scanf ("%d", &IsEdgePresent);
            
            if (IsEdgePresent)
                Graph [i][j] = 1;
            
            else if (! IsEdgePresent)
                Graph [i][j] = 0;
        }
    }
}

void displayGraph (const int Graph [][10], int V)
{
    printf ("Matrix representation of graph:\n");
    
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf ("%d\t", Graph [i][j]);
        
        printf ("\n");
    }
}

void _depthFirstSearch (const int Graph [][10], int V, int SourceVertex, int IsVisited [])
{
    printf ("%d\t", SourceVertex);
    IsVisited [SourceVertex] = 1;
    
    for (int i = 0; i < V; i++)
    {
        int AdjacentVertex = i;
        int IsAdjacent = Graph [SourceVertex][AdjacentVertex];
        
        if (IsAdjacent && ! IsVisited [AdjacentVertex])
            _depthFirstSearch(Graph, V, AdjacentVertex, IsVisited);
    }
}

void depthFirstSearch (int Graph [][10], int V, int StartVertex)
{
    int IsVisited [10] = {0};
    _depthFirstSearch (Graph, V, StartVertex, IsVisited);
}

int main (int argc, const char * argv[])
{
    int Graph [10][10];
    int V;
    int IsUndirected;
    
    printf ("Enter number of vertices:");
    scanf ("%d", &V);
    
    printf ("Is graph Undirected?\n");
    scanf ("%d", &IsUndirected);

    if (IsUndirected)
        readUnweightedUndirectedGraph (Graph, V);
    
    else
        readUnweightedDirectedGraph (Graph, V);
    
    printf ("The graph is:\n");
    displayGraph (Graph, V);
    
    int StartVertex;
    printf ("Enter start vertex:\n");
    scanf ("%d", &StartVertex);
    
    depthFirstSearch (Graph, V, StartVertex);
    return 0;
}
