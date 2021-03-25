#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

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
    q->rear=(q->rear+1) % SIZE;
    q->elements[q->rear] = e;
    if (q->front==-1)
        q->front = 0;
}

int deQueue (struct Queue *q)
{
    int e = q->elements[q->front];
    
    if(q->rear == q->front)
        q->rear = q->front = -1;
    
    else
        q->front=(q->front+1)%SIZE;
    return e;
}

int isEmpty (const struct Queue *q)
{
    if(q->front == -1)
        return 1;
    
    else
        return 0;
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

void displayGraph (const int Graph [][10], int V)
{
    printf ("Matrix representation of graph:\n");
    
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf ("%d\t", Graph [i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

int doesCycleExist (int Graph [][10], int V, int StartVertex)
{
    int IsVisited [10] = {0};
    
    sq Queue;
    initQueue (&Queue);
    
    enQueue(&Queue, StartVertex);
    IsVisited [StartVertex] = 1;
    
    while (! isEmpty (&Queue))
    {
        int SourceVertex = deQueue (&Queue);
        
        for (int i = 0; i < V; i++)
        {
            int AdjacentVertex = i;
            int IsAdjacent = Graph [SourceVertex][AdjacentVertex];
            
            if (IsAdjacent && ! IsVisited [AdjacentVertex])
            {
                IsVisited [AdjacentVertex] = 1;
                enQueue (&Queue, AdjacentVertex);
            }
            
            else if (IsAdjacent && IsVisited [AdjacentVertex])
                return 1;
        }
    }
    return 0;
}

void computeColumnSum (int Graph [][10], int V, int * indegree, sq * q)
{
    for (int j = 0; j < V; j++)
    {
        int ColumnSum = 0;
        
        for (int i = 0; i < V; i++)
            ColumnSum += Graph [i][j];
        
        indegree [j] = ColumnSum;
        
        if (! indegree [j])     //enQueue if in-degree of vertex is 0.
            enQueue(q, j);
    }
}

int topologicalSort (int Graph [][10], int V)
{
    int indegree [10];
    
    sq q;
    initQueue (&q);
    
    if (doesCycleExist (Graph, V, 0))
        return 0;
    
    computeColumnSum(Graph, V, indegree, &q);
    
    if (isEmpty (&q))       //No vertices with in-degree = 0
        return 0;
    
    printf ("Topological sort of the graph is:\n");
    
    while (!isEmpty (&q))
    {
        int SourceVertex = deQueue (&q);
        printf ("%d\t", SourceVertex);
        
        for (int i = 0; i < V; i++)
        {
            int AdjacentVertex = i;
            int IsAdjacent = Graph [SourceVertex][AdjacentVertex];
            
            if (IsAdjacent)
            {
                indegree [AdjacentVertex]--;        //Every adjacent vertex's in-degree reduced by 1
            
                if (! indegree [AdjacentVertex])
                    enQueue (&q, AdjacentVertex);
            }
        }
    }
    printf ("\n\n");
    return 1;
}

int main (int argc, const char * argv[])
{
    int Graph [10][10];
    int V;
    
    printf ("Enter number of vertices:");
    scanf ("%d", &V);

    readUnweightedDirectedGraph (Graph, V);
    
    printf ("The graph is:\n");
    displayGraph (Graph, V);
    
    int IsTopologicalSortPossible = topologicalSort (Graph, V);
    
    if (! IsTopologicalSortPossible)
        printf ("ERROR -- Topological sort cannot be applied!\n");
}