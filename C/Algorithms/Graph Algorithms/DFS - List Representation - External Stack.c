#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//INCORRECT

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

void depthFirstSearch (n * Graph, int V, int StartVertex)
{
    int IsVisited [10] = {0};
    
    n * p = Graph [StartVertex].next;
    
    ss s;
    initStack (&s);
    push (&s, StartVertex);
    
    while (! isEmpty (&s))
    {
        int u = pop (&s);
        
        if (! IsVisited [u])
        {
            printf ("%d\t", u);
            IsVisited [u] = 1;
        }
        
        p = Graph [u].next;
        
        while (p)
        {
            if (! IsVisited [p->vertex])
            {
                push (&s, p->vertex);
                break;
            }
            p = p->next;
        }
    }
}

int main (int argc, const char * argv[])
{
    int V;
    printf ("Enter number of vertices:");
    scanf ("%d", &V);
    
    n * Graph = (n *) malloc (sizeof (n) * V);
    initGraph (Graph, V);
    
    printf ("Enter graph:\n");
    readUnweightedGraph (Graph, V);
    
    printf ("The graph is:\n");
    displayGraph (Graph, V);
    
    int StartVertex;
    printf ("Enter start vertex:");
    scanf ("%d", &StartVertex);
    
    depthFirstSearch (Graph, V, StartVertex);
    free (Graph);
    return 0;
}
