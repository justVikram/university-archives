#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int IndexOfVertex [100];        // Tells us the index in the heap at which the vertex is available
int IsVertexAvailable [100];        // Tells us whether the vertex is available in the heap data structure or not

typedef struct vertex
{
    int V;
    int WeightOfAssociatedEdge;
}sv;

typedef struct node
{
    sv VertexData;
    struct node * next;
}n;

//MARK:-

typedef struct graph
{
    n * FirstNode;
    n * LastNode;
}sg;

static void initGraph (sg Graph[])
{
    for (int i = 0; i < 100; i++)
    {
        Graph [i].FirstNode = NULL;
        Graph [i].LastNode = NULL;
    }
}

//MARK:-

typedef struct heap
{
    sv array [100];
    int size;
}sh;

static void initHeap (sh * Heap)
{
    Heap->size = 0;
}

static void fillHeapWithVertexData (sh * Heap, int V)
{
    for (int i = 0; i < V; i++)
    {
        Heap->array [i].V = i;
        Heap->array [i].WeightOfAssociatedEdge = INT_MAX;       //Initially, weight of all edges = ∞
    }
    Heap->size = V;
}

static void swapVertexNodes (sv * VertexNode1, sv * VertexNode2)
{
    sv temp = *VertexNode1;
    *VertexNode1 = *VertexNode2;
    *VertexNode2 = temp;
}

static void swapIndices (int * Index1, int * Index2)
{
    int temp = *Index1;
    *Index1 = *Index2;
    *Index2 = temp;
}

static void decreaseKey (sh * Heap, int i, int DecreasedKey)
{
    Heap->array [i].WeightOfAssociatedEdge = DecreasedKey;
    
    int ChildIndex = i;
    int IsChildIndexZero = ChildIndex == 0;
    int ParentIndex = (ChildIndex - 1) / 2;
    
    int ChildWeight = Heap->array [ChildIndex].WeightOfAssociatedEdge;
    int ParentWeight = Heap->array [ParentIndex].WeightOfAssociatedEdge;
    
    while (! IsChildIndexZero && ChildWeight < ParentWeight)
    {
        swapVertexNodes (&Heap->array [ChildIndex], &Heap->array [ParentIndex]);
        swapIndices (&IndexOfVertex [ChildIndex], &IndexOfVertex [ParentIndex]);
        
        ChildIndex = ParentIndex;
        IsChildIndexZero = ChildIndex == 0;
        ParentIndex = (ChildIndex - 1) / 2;
        
        ChildWeight = Heap->array [ChildIndex].WeightOfAssociatedEdge;
        ParentWeight = Heap->array [ParentIndex].WeightOfAssociatedEdge;
    }
}

static int isEmpty (sh * Heap)
{
    return Heap->size == 0;
}

static void updateMinElementIndex(sh *Heap, int * MinElementIndex)
{
    int LeftChildIndex = 2 * *MinElementIndex + 1;
    int RightChildIndex = 2 * *MinElementIndex + 2;
    
    int IsLeftIndexValid = LeftChildIndex < Heap->size;
    int IsRightIndexValid = RightChildIndex < Heap->size;
    
    int IsLeftChildSmaller = Heap->array [LeftChildIndex].WeightOfAssociatedEdge < Heap->array [* MinElementIndex].WeightOfAssociatedEdge;
    int IsRightChildSmaller = Heap->array [RightChildIndex].WeightOfAssociatedEdge < Heap->array [* MinElementIndex].WeightOfAssociatedEdge;
    
    if (IsLeftIndexValid && IsLeftChildSmaller)
        *MinElementIndex = LeftChildIndex;
    
    if (IsRightIndexValid && IsRightChildSmaller)
        *MinElementIndex = RightChildIndex;
}

static void heapify (sh * Heap, int i)
{
    int MinElementIndex = i;
    updateMinElementIndex(Heap, &MinElementIndex);
    
    int WasMinElementIndexUpdated = MinElementIndex != i;
    
    if (WasMinElementIndexUpdated)
    {
        swapVertexNodes(&Heap->array [i], &Heap->array [MinElementIndex]);
        swapIndices(&IndexOfVertex [Heap->array [i].V], &IndexOfVertex [Heap->array [MinElementIndex].V]);
        
        heapify (Heap, MinElementIndex);
    }
}

static sv extractMin (sh * Heap)
{
    sv MinVertexNode = Heap->array [0];
    int IndexOfLastAddedVertex = --Heap->size;
    
    Heap->array [0] = Heap->array [IndexOfLastAddedVertex];
    IsVertexAvailable [MinVertexNode.V] = 0;
    IndexOfVertex [Heap->array [0].V] = 0;
    
    heapify (Heap, 0);
    
    return MinVertexNode;
}

//MARK:-

static void trackVerticesAndTheirIndex (int V)
{
    for (int i = 0; i < V; i++)
    {
        IndexOfVertex [i] = i;
        IsVertexAvailable [i] = 1;
    }
}

//MARK:-

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

static void getSourceVertex (int * SourceVertex)
{
    printf ("Enter source vertex:");
    scanf ("%d", SourceVertex);
}

static void addEdge (sg Graph [], int SourceVertex, int AdjacentVertex, int WeightOfEdge)
{
    n * VertexNode;
    VertexNode = (n *) malloc (sizeof (n));
    
    VertexNode->VertexData.V = AdjacentVertex;
    VertexNode->VertexData.WeightOfAssociatedEdge = WeightOfEdge;
    VertexNode->next = NULL;
    
    n * AreThereAdjacentNodes = Graph [SourceVertex].FirstNode;
    
    if (! AreThereAdjacentNodes)
    {
        Graph [SourceVertex].FirstNode = VertexNode;
        Graph [SourceVertex].LastNode = VertexNode;
    }
    else
    {
        Graph [SourceVertex].LastNode->next = VertexNode;
        Graph [SourceVertex].LastNode = VertexNode;
    }
}

static void getShortestPaths (int DistanceFromSource [100], int V, int SourceVertex)
{
    for (int i = 1; i < V; i++)
    printf ("Distance from vertex %d to vertex %d is %d\n", SourceVertex, i, DistanceFromSource [i]);
}

static void performRelaxation (sh * Heap, const sv * MinWeightVertexNode, n * AdjacentVertexNode)
{
    sv AdjacentVertexData = AdjacentVertexNode->VertexData;
    int AdjacentVertex = AdjacentVertexData.V;
    
    int EffectiveDistance = MinWeightVertexNode->WeightOfAssociatedEdge + AdjacentVertexData.WeightOfAssociatedEdge;
    int OriginalDistance = Heap->array [AdjacentVertexData.V].WeightOfAssociatedEdge;
    
    if (IsVertexAvailable [AdjacentVertex] && EffectiveDistance < OriginalDistance)
        decreaseKey(Heap, IndexOfVertex [AdjacentVertex], EffectiveDistance);
}

static void djikstraAlgorithm (sg Graph [], int V, int SourceVertex)
{
    sh Heap;
    initHeap (&Heap);
    fillHeapWithVertexData (&Heap, V);
    
    int distanceFromSource [100];
    
    trackVerticesAndTheirIndex (V);
    decreaseKey(&Heap, IndexOfVertex [SourceVertex], 0);
    
    while (!isEmpty (&Heap))
    {
        sv MinWeightVertexNode = extractMin (&Heap);
        distanceFromSource [MinWeightVertexNode.V] = MinWeightVertexNode.WeightOfAssociatedEdge;
        
        n * AdjacentVertexNode = Graph [MinWeightVertexNode.V].FirstNode;
        
        while (AdjacentVertexNode)
        {
            performRelaxation (&Heap, &MinWeightVertexNode, AdjacentVertexNode);
            AdjacentVertexNode = AdjacentVertexNode->next;
        }
    }
    getShortestPaths(distanceFromSource, V, SourceVertex);
}

//MARK:-

int main (int argc, const char * argv[])
{
    sg Graph [100];
    initGraph (Graph);
    
    int V;
    printf("Enter the number of vertices:");
    scanf("%d",&V);
    
    for (int i = 0; i < V; i++)
    {
        int E;
        printf ("Enter number of edges from vertex %d:", i);
        scanf ("%d", &E);
        
        for (int j = 0; j < E; j++)
        {
            int AdjacentVertex;
            getAdjacentVertex (&AdjacentVertex);
            
            int WeightOfEdge;
            getWeightOfEdge (&WeightOfEdge);
            
            addEdge (Graph, i, AdjacentVertex, WeightOfEdge);
        }
    }
    int SourceVertex;
    getSourceVertex(&SourceVertex);
    
    printf ("Displaying shortest paths:\n");
    djikstraAlgorithm (Graph, V, SourceVertex);
    
    return 0;
}
