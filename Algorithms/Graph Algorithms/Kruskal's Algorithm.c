#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define sortEdgesInAscOrder qsort


static int NumberOfEdgesStored = 0;
static int NumberOfEdgesSelected = 0;

typedef struct Edge
{
    int SourceVertex;
    int AdjacentVertex;
    int WeightOfEdge;
}
EDGE;

typedef struct vertex
{
    int V;
    int WeightOfAssociatedEdge;
}
VERTEX;

typedef struct node
{
    VERTEX VertexData;
    struct node * next;
}
NODE;

typedef struct Graph
{
    struct node * FirstNode;
    struct node * LastNode;
}
GRAPH;

typedef struct subset
{
    int parent;
    int rank;
}
SUBSET;

SUBSET S [MAX];

static void initGraph (GRAPH G [])
{
    for (int i = 0; i < MAX; i++)
    {
        G [i].FirstNode = NULL;
        G [i].LastNode = NULL;
    }
}

static void addEdge (GRAPH G [], int SourceVertex, int AdjacentVertex, int WeightOfEdge)
{
    NODE * NewVertexNode = (NODE *) malloc (sizeof (NODE));
    NewVertexNode->VertexData.V = AdjacentVertex;
    NewVertexNode->VertexData.WeightOfAssociatedEdge = WeightOfEdge;
    NewVertexNode->next = NULL;
    
    NODE * AreThereAdjacentNodes = G [SourceVertex].FirstNode;
    
    if (! AreThereAdjacentNodes)
        G [SourceVertex].FirstNode = NewVertexNode;
    
    else
        G [SourceVertex].LastNode->next = NewVertexNode;
    
    G [SourceVertex].LastNode = NewVertexNode;
}

static void deleteGraph (struct Graph G [])
{
    for (int i = 0; i < MAX; i++)
    {
        NODE * NodeToBeDeleted = G [i].FirstNode;
        NODE * IsThereAnotherNode = NodeToBeDeleted;
        
        while (IsThereAnotherNode)
        {
            G [i].FirstNode = NodeToBeDeleted->next;
            free (NodeToBeDeleted);
            
            NodeToBeDeleted = G [i].FirstNode;
            IsThereAnotherNode = NodeToBeDeleted;
        }
    }
}

///  qsort() expects the comparison function to return:
///  -ve result if val1 < val2
///  0 if val1 == val2
///  +ve result if val1 > val2
int qSortComparator (const void *a, const void *b)
{
    EDGE *p = (EDGE *) a;
    EDGE *q = (EDGE *) b;
    return p->WeightOfEdge - q->WeightOfEdge;
}

void displayMST (EDGE SelectedEdges [], int NumberOfEdgesSelected)
{
    int SumOfMST = 0;
    
    printf ("The following edges are selected in Kruskal's MST \n");
    
    for (int i = 0; i < NumberOfEdgesSelected; i++)
    {
        int SourceVertex = SelectedEdges[i].SourceVertex;
        int AdjacentVertex = SelectedEdges[i].AdjacentVertex;
        int WeightOfEdge = SelectedEdges[i].WeightOfEdge;
        
        printf ("%d --> %d with weight %d\n", SourceVertex, AdjacentVertex, WeightOfEdge);
        
        SumOfMST += SelectedEdges[i].WeightOfEdge;
    }
    printf ("Minimum cost spanning tree is %d\n", SumOfMST);
}

static void initSubsets (int V)
{
    for (int i = 0; i < V; i++)
    {
        S [i].parent = i;
        S [i].rank = 0;
    }
}


static int findByPathCompression (int element)
{
    
    if (S [element].parent != element)
        S[element].parent = findByPathCompression (S [element].parent);

    return S [element].parent;
}

static int getRank (int element)
{
    return S [element].rank;
}

static void incrementRank (int ParentOfElement)
{
    S [ParentOfElement].rank++;
}

static void updateParent (int CurrentParent, int NewParent)
{
    S [CurrentParent].parent = NewParent;
}

static void unionByRank (int ElementA, int ElementB)
{
    int ParentOfA = findByPathCompression (ElementA);
    int ParentOfB = findByPathCompression (ElementB);
    
    if(ParentOfA != ParentOfB)
    {
        if(getRank (ParentOfA) < getRank (ParentOfB))
            updateParent(ParentOfA, ParentOfB);

        else if (getRank (ParentOfB) < getRank (ParentOfA))
            updateParent(ParentOfB, ParentOfA);

        else
        {
            updateParent (ParentOfB, ParentOfA);
            incrementRank (ParentOfA);
        }
    }
}

static void storeAllEdges (EDGE E [], GRAPH G [], int V)
{
    for (int i = 0; i < V; i++)
    {
        NODE * AdjacentNode = G [i].FirstNode;
        
        while (AdjacentNode)
        {
            E [NumberOfEdgesStored].SourceVertex = i;
            E [NumberOfEdgesStored].AdjacentVertex = (AdjacentNode->VertexData).V;
            E [NumberOfEdgesStored].WeightOfEdge = (AdjacentNode->VertexData).WeightOfAssociatedEdge;
            
            NumberOfEdgesStored++;
            AdjacentNode = AdjacentNode->next;
        }
    }
}

static void getAdjacentVertex (int * AdjacentVertex)
{
    printf ("Enter adjacent vertex:");
    scanf ("%d", AdjacentVertex);
}

static void getWeightOfEdge (int * WeightOfEdge)
{
    printf ("Enter weight of the associated edge:");
    scanf ("%d", WeightOfEdge);
}

static void applyKruskalAlgorithm (EDGE StoredEdges [], EDGE SelectedEdges [], int V)
{
    for (int i = 0; i < NumberOfEdgesStored; i++)
    {
        int SourceVertex = StoredEdges [i].SourceVertex;
        int AdjacentVertex = StoredEdges [i].AdjacentVertex;
        
        int ParentOfSourceVertex = findByPathCompression (SourceVertex);
        int ParentOfAdjacentVertex = findByPathCompression (AdjacentVertex);
        
        if (ParentOfSourceVertex != ParentOfAdjacentVertex)
        {
            SelectedEdges [NumberOfEdgesSelected] = StoredEdges [i];
            NumberOfEdgesSelected++;
            
            unionByRank (ParentOfSourceVertex, ParentOfAdjacentVertex);
            
            if (NumberOfEdgesSelected == V - 1)
                break;
        }
    }
}

void kruskalAlgorithm (GRAPH G [], int V)
{
    initSubsets (V);
    EDGE StoredEdges [MAX * MAX];
    EDGE SelectedEdges [MAX];
    
    storeAllEdges (StoredEdges, G, V);
    sortEdgesInAscOrder (StoredEdges, NumberOfEdgesStored, sizeof (EDGE), qSortComparator);

    applyKruskalAlgorithm (StoredEdges, SelectedEdges, V);
    displayMST (SelectedEdges, NumberOfEdgesSelected);
}

//MARK:-

int main (int argC, const char * argV [])
{
    GRAPH G [MAX];
    initGraph (G);
    
    int V;
    printf ("Enter number of vertices :");
    scanf ("%d",&V);
    
    for(int i = 0; i < V; i++)
    {
        int E;
        printf ("Enter number of edges from source %d : ", i);
        scanf ("%d", &E);
        
        for(int j = 0; j < E; j++)
        {
            int AdjacentVertex;
            getAdjacentVertex (&AdjacentVertex);
            
            int WeightOfEdge;
            getWeightOfEdge (&WeightOfEdge);
            
            addEdge(G, i, AdjacentVertex, WeightOfEdge);
        }
    }
    kruskalAlgorithm (G, V);
    
    deleteGraph (G);
    return 0;
}
