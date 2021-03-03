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
}VERTEX;

typedef struct node
{
    VERTEX VertexData;
    struct node * next;
}NODE;

//MARK:-

typedef struct graph
{
    NODE * FirstNode;
    NODE * LastNode;
}
GRAPH;

static void initGraph (GRAPH G [])
{
    for (int i = 0; i < 100; i++)
    {
        G [i].FirstNode = NULL;
        G [i].LastNode = NULL;
    }
}

//MARK:-

typedef struct heap
{
    VERTEX HeapArray [100];
    int SizeOfHeap;
}HEAP;

static void initHeap (HEAP * H)
{
    H->SizeOfHeap = 0;
}

static void fillHeapWithVertexData (HEAP * H, int V)
{
    for (int i = 0; i < V; i++)
    {
        H->HeapArray [i].V = i;
        H->HeapArray [i].WeightOfAssociatedEdge = INT_MAX;       //Initially, weight of all edges = ∞
    }
    H->SizeOfHeap = V;
}

static void swapVertexData (VERTEX * VertexNode1, VERTEX * VertexNode2)
{
    VERTEX temp = *VertexNode1;
    *VertexNode1 = *VertexNode2;
    *VertexNode2 = temp;
}

static void swapIndices (int * Index1, int * Index2)
{
    int temp = *Index1;
    *Index1 = *Index2;
    *Index2 = temp;
}

static void decreaseKey (HEAP * H, int IndexOfElementToBeDecreased, int DecreasedWeight)
{
    H->HeapArray [IndexOfElementToBeDecreased].WeightOfAssociatedEdge = DecreasedWeight;
    
    int ChildIndex = IndexOfElementToBeDecreased;
    int IsChildIndexZero = ChildIndex == 0;
    int ParentIndex = (ChildIndex - 1) / 2;
    
    int ChildWeight = H->HeapArray [ChildIndex].WeightOfAssociatedEdge;
    int ParentWeight = H->HeapArray [ParentIndex].WeightOfAssociatedEdge;
    
    while (! IsChildIndexZero && ChildWeight < ParentWeight)
    {
        swapVertexData (&H->HeapArray [ChildIndex], &H->HeapArray [ParentIndex]);
        swapIndices (&IndexOfVertex [H->HeapArray [ChildIndex].V], &IndexOfVertex [H->HeapArray [ParentIndex].V]);
        
        ChildIndex = ParentIndex;
        IsChildIndexZero = ChildIndex == 0;
        ParentIndex = (ChildIndex - 1) / 2;
        
        ChildWeight = H->HeapArray [ChildIndex].WeightOfAssociatedEdge;
        ParentWeight = H->HeapArray [ParentIndex].WeightOfAssociatedEdge;
    }
}

static int isEmpty (HEAP * H)
{
    return H->SizeOfHeap == 0;
}

static void updateMinElementIndex (HEAP *H, int * MinElementIndex)
{
    int LeftChildIndex = 2 * (*MinElementIndex) + 1;
    int RightChildIndex = 2 * (*MinElementIndex) + 2;
    
    int IsLeftIndexValid = LeftChildIndex < H->SizeOfHeap;
    int IsRightIndexValid = RightChildIndex < H->SizeOfHeap;
    
    int IsLeftChildSmaller = H->HeapArray [LeftChildIndex].WeightOfAssociatedEdge < H->HeapArray [* MinElementIndex].WeightOfAssociatedEdge;
    int IsRightChildSmaller = H->HeapArray [RightChildIndex].WeightOfAssociatedEdge < H->HeapArray [* MinElementIndex].WeightOfAssociatedEdge;
    
    if (IsLeftIndexValid && IsLeftChildSmaller)
        *MinElementIndex = LeftChildIndex;
    
    if (IsRightIndexValid && IsRightChildSmaller)
        *MinElementIndex = RightChildIndex;
}

static void heapify (HEAP * H, int i)   //From top to down
{
    int MinElementIndex = i;
    updateMinElementIndex (H, &MinElementIndex);
    
    int WasMinElementIndexUpdated = MinElementIndex != i;
    
    if (WasMinElementIndexUpdated)
    {
        swapVertexData (&H->HeapArray [i], &H->HeapArray [MinElementIndex]);      //If MinElementIndex was updated, then i != MinElementIndex
        swapIndices (&IndexOfVertex [H->HeapArray [i].V], &IndexOfVertex [H->HeapArray [MinElementIndex].V]);
        
        heapify (H, MinElementIndex);
    }
}

static VERTEX extractMin (HEAP * H)
{
    VERTEX MinWeightVertexData = H->HeapArray [0];
    int IndexOfLastAddedVertex = -- H->SizeOfHeap;
    
    H->HeapArray [0] = H->HeapArray [IndexOfLastAddedVertex];
    IsVertexAvailable [MinWeightVertexData.V] = 0;        //As soon as vertex is removed from heap, it becomes unavailable
    IndexOfVertex [H->HeapArray [0].V] = 0;
    
    heapify (H, 0);
    
    return MinWeightVertexData;
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

static void addEdge (GRAPH G [], int SourceVertex, int AdjacentVertex, int WeightOfEdge)
{
    NODE * VertexNode = (NODE *) malloc (sizeof (NODE));
    VertexNode->VertexData.V = AdjacentVertex;
    VertexNode->VertexData.WeightOfAssociatedEdge = WeightOfEdge;
    VertexNode->next = NULL;
    
    NODE * AreThereAdjacentNodes = G [SourceVertex].FirstNode;
    
    if (! AreThereAdjacentNodes)
        G [SourceVertex].FirstNode = VertexNode;
    
    else
        G [SourceVertex].LastNode->next = VertexNode;
    
    G [SourceVertex].LastNode = VertexNode;
}

static void getShortestPathsFromSource (int DistanceFromSource [100], int V, int SourceVertex)
{
    for (int i = 0; i < V; i++)
    {
        if (i != SourceVertex)
        {
            if (DistanceFromSource [i] == INT_MAX)
                printf ("Distance from vertex %d to vertex %d is ∞\n", SourceVertex, i);
            
            else
                printf ("Distance from vertex %d to vertex %d is %d\n", SourceVertex, i, DistanceFromSource [i]);
        }
    }
}

static void performRelaxation (HEAP * H, const VERTEX * MinWeightVertexData, NODE * AdjacentVertexNode)
{
    VERTEX AdjacentVertexData = AdjacentVertexNode->VertexData;
    int AdjacentVertex = AdjacentVertexData.V;
    
    int DistanceToExtractedVertex = MinWeightVertexData->WeightOfAssociatedEdge;
    int DistanceFromExtractedVertex = AdjacentVertexData.WeightOfAssociatedEdge;
    
    int EffectiveDistance = DistanceToExtractedVertex + DistanceFromExtractedVertex;
    int OriginalDistance = H->HeapArray [AdjacentVertex].WeightOfAssociatedEdge;
    
    if (IsVertexAvailable [AdjacentVertex] && EffectiveDistance < OriginalDistance)
        decreaseKey(H, IndexOfVertex [AdjacentVertex], EffectiveDistance);
}

static void dijkstraAlgorithm (GRAPH G [], int V, int SourceVertex)
{
    HEAP H;
    initHeap (&H);
    fillHeapWithVertexData (&H, V);
    
    int DistanceFromSource [100] = {-1};
    
    trackVerticesAndTheirIndex (V);
    decreaseKey (&H, IndexOfVertex [SourceVertex], 0);
    
    while (!isEmpty (&H))
    {
        VERTEX MinWeightVertexData = extractMin (&H);
        DistanceFromSource [MinWeightVertexData.V] = MinWeightVertexData.WeightOfAssociatedEdge;
        
        NODE * AdjacentVertexNode = G [MinWeightVertexData.V].FirstNode;
        
        while (AdjacentVertexNode)
        {
            performRelaxation (&H, &MinWeightVertexData, AdjacentVertexNode);
            AdjacentVertexNode = AdjacentVertexNode->next;
        }
    }
    getShortestPathsFromSource(DistanceFromSource, V, SourceVertex);
}

//MARK:-

int main (int argc, const char * argv[])
{
    GRAPH G [100];
    initGraph (G);
    
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
            
            addEdge (G, i, AdjacentVertex, WeightOfEdge);
        }
    }
    int SourceVertex;
    getSourceVertex(&SourceVertex);
    
    printf ("Displaying shortest paths:\n");
    dijkstraAlgorithm (G, V, SourceVertex);
    
    return 0;
}
