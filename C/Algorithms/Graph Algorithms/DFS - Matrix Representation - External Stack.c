#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//vertex till the point we have checked is available at the top of the stack, no need to maintain "LastVertexVisited"


typedef struct stack
{
    int elements[SIZE];
    int top;
}ss;


void initStack(struct stack *s)
{
    s->top = -1;
}


int isFull (const struct stack * s)
{
    return s->top == SIZE - 1;
}


void push (struct stack * s, int e)
{
    s->top++;
    s->elements [s->top] = e;
}


int isEmpty (const struct stack * s)
{
    return s->top == -1;
}


int pop (struct stack * s)
{
    int e = s->elements[s->top];
    s->top--;
    return e;
}

int peek (const struct stack * s)
{
    return s->elements[s->top];
}

void display (const struct stack * s)
{
    for(int i = s->top;i>=0;i--)
        printf("%d\n",s->elements[i]);
}

int size (const struct stack *s)
{
    return s->top+1;
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
}

void depthFirstSearch_ExternalStack (int Graph [][10], int V, int StartVertex)
{
    int IsVisited [10] = {0};
    int SomeVertex = 0;
    ss Stack;
    initStack (&Stack);
    push (&Stack, StartVertex);
    IsVisited [StartVertex] = 1;
    printf ("%d\t", StartVertex);
    
    while (!isEmpty (&Stack))
    {
        for (/*Fetch current value of SomeVertex*/ ; SomeVertex < V; SomeVertex++)
        {
            int CurrentVertex = peek (&Stack);
            int IsAdjacent = Graph [CurrentVertex][SomeVertex];
            
            if (IsAdjacent && ! IsVisited [SomeVertex])
            {
                IsVisited [SomeVertex] = 1;
                printf ("%d\t", SomeVertex);
                push (&Stack, SomeVertex);
                break;
            }
        }
            if (SomeVertex == V)
                SomeVertex = pop (&Stack) + 1;
        
            else
                SomeVertex = 0;
    }
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
    
    depthFirstSearch_ExternalStack (Graph, V, StartVertex);
    return 0;
}
