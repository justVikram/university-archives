
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Node
{
    int vertex;
    struct Node * next;
}n;

void initGraph (n * Graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        Graph [i].vertex = i;
        Graph [i].next = NULL;
    }
}

void addEdge (n * NodeOfGraph, int j)
{
    n * NewNode = (n *) malloc (sizeof (n));
    NewNode->vertex = j;
    NewNode->next = NULL;
    
    if (! NodeOfGraph->next)
        NodeOfGraph->next = NewNode;
    
    else
    {
        n * cur = NodeOfGraph;
        
        while (cur->next)
            cur = cur->next;
        
        cur->next = NewNode;
    }
}

void readUnweightedGraph (n * Graph, int V)
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

typedef struct Queue
{
    int elements[SIZE];
    int front, rear;
}sq;

void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}


void enQueue(struct Queue *q, int e)
{
    q->rear=(q->rear+1)%SIZE;
    q->elements[q->rear]=e;
    if(q->front==-1)
        q->front = 0;
}

int deQueue(struct Queue *q)
{
    int e = q->elements[q->front];
    
    if(q->rear == q->front)
        q->rear = q->front = -1;
    
    else
        q->front=(q->front+1)%SIZE;
    return e;
}

int isEmpty(const struct Queue *q)
{
    if(q->front == -1)
        return 1;
    
    else
        return 0;
}

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
            {
                Graph [i][j] = Graph [j][i] = 1;
            }
            
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
            {
                Graph [i][j] = 1;
            }
            
            else if (! IsEdgePresent)
                Graph [i][j] = 0;
        }
    }
}

void displayGraph (n* Graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        n * cur = Graph [i].next;
        
        while (cur)
        {
            printf ("Edge between %d and %d\n", i, cur->vertex);
            cur = cur->next;
        }
        
    }
}

void breadthFirstSearch (n * Graph, int V, int StartVertex)
{
    int * IsVisited = (int *) calloc (sizeof (int), V);
    
    sq Queue;
    initQueue(&Queue);
    
    enQueue(&Queue, StartVertex);
    IsVisited [StartVertex] = 1;
    
    while (!isEmpty(&Queue))
    {
        int HeadVertex = deQueue(&Queue);
        printf ("%d\t", HeadVertex);
        
        n * AdjacentVertexNode = Graph [HeadVertex].next;
        
        while (AdjacentVertexNode)
        {
            int AdjacentVertex = AdjacentVertexNode->vertex;
            
            if (! IsVisited [AdjacentVertex])
            {
                enQueue(&Queue, AdjacentVertex);
                IsVisited [AdjacentVertex] = 1;
            }
            AdjacentVertexNode = AdjacentVertexNode->next;
        }
    }
    free (IsVisited);
}

int main (int argc, const char * argv[])
{
    int V;
    int StartVertex;
    
    printf ("Enter number of vertices:");
    scanf ("%d", &V);
    
    n * Graph = (n *) malloc (sizeof (n) * V);
    initGraph (Graph, V);
    
    printf ("Enter graph:\n");
    readUnweightedGraph (Graph, V);
    
    printf ("The graph is:\n");
    displayGraph (Graph, V);
    
    printf ("Enter start vertex:");
    scanf ("%d", &StartVertex);
    
    breadthFirstSearch (Graph, V, StartVertex);
    free (Graph);
    return 0;
}


