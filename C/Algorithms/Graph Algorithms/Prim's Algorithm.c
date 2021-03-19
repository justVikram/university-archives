#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100
#define PARENT_OF 0
#define WEIGHT_OF 1

int IndexOfVertex [MAX];
int IsVertexAvailable [MAX];


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

//MARK:-

typedef struct Graph
{
    NODE * FirstNode;
    NODE * LastNode;
}
GRAPH;

static void initGraph(GRAPH G [])
{
    for (int i = 0; i < 100; i++)
    {
        G [i].FirstNode = NULL;
        G [i].LastNode = NULL;
    }
}

//MARK:-

typedef struct Heap
{
    VERTEX HeapArray [MAX];
    int SizeOfHeap;
}
HEAP;

static void initHeap (HEAP * H)
{
    H->SizeOfHeap = 0;
}

static void swapVertexNodes (VERTEX * VertexNode1, VERTEX * VertexNode2)
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

static void insertKey (HEAP * H, VERTEX NewVertexData)
{
    H->HeapArray [H->SizeOfHeap] = NewVertexData;
    int ChildIndex = H->SizeOfHeap++;
    int ParentIndex = (ChildIndex - 1) / 2;
    
    int IsChildWeightLesser = H->HeapArray[ChildIndex].WeightOfAssociatedEdge < H->HeapArray[ParentIndex].WeightOfAssociatedEdge;
    
    while (ChildIndex!=0 && IsChildWeightLesser)
    {
        swapVertexNodes (&H->HeapArray[ChildIndex], &H->HeapArray[ParentIndex]);
        swapIndices (&IndexOfVertex[ChildIndex], &IndexOfVertex[ParentIndex]);
        
        ChildIndex = ParentIndex;
        ParentIndex = (ChildIndex - 1) / 2;
        
        IsChildWeightLesser = H->HeapArray[ChildIndex].WeightOfAssociatedEdge < H->HeapArray[ParentIndex].WeightOfAssociatedEdge;
    }
}

static int isEmpty(struct Heap * H)
{
    return H->SizeOfHeap == 0;
}

static void updateMinElementIndex(HEAP *H, int * MinElementIndex)
{
    int LeftChildIndex = 2 * *MinElementIndex + 1;
    int RightChildIndex = 2 * *MinElementIndex + 2;
    
    int IsLeftIndexValid = LeftChildIndex < H->SizeOfHeap;
    int IsRightIndexValid = RightChildIndex < H->SizeOfHeap;
    
    int IsLeftChildSmaller = H->HeapArray [LeftChildIndex].WeightOfAssociatedEdge < H->HeapArray [* MinElementIndex].WeightOfAssociatedEdge;
    int IsRightChildSmaller = H->HeapArray [RightChildIndex].WeightOfAssociatedEdge < H->HeapArray [* MinElementIndex].WeightOfAssociatedEdge;
    
    if (IsLeftIndexValid && IsLeftChildSmaller)
        *MinElementIndex = LeftChildIndex;
    
    if (IsRightIndexValid && IsRightChildSmaller)
        *MinElementIndex = RightChildIndex;
}

static void heapify (struct Heap * H, int i)
{
    int MinElementIndex = i;
    updateMinElementIndex(H, &MinElementIndex);
    
    int WasMinElementIndexUpdated = MinElementIndex != i;
    
    if (WasMinElementIndexUpdated)
    {
        swapVertexNodes (&H->HeapArray [i], &H->HeapArray [MinElementIndex]);      //If MinElementIndex was updated, then i != MinElementIndex
        swapIndices (&IndexOfVertex [H->HeapArray [i].V], &IndexOfVertex [H->HeapArray [MinElementIndex].V]);
        
        heapify (H, MinElementIndex);
    }
}

static VERTEX extractMin (HEAP * H)
{
    VERTEX MinVertexNode = H->HeapArray [0];
    int IndexOfLastAddedVertex = --H->SizeOfHeap;
    
    H->HeapArray [0] = H->HeapArray [IndexOfLastAddedVertex];
    IsVertexAvailable [MinVertexNode.V] = 0;        //As soon as vertex is removed from heap, it becomes unavailable
    IndexOfVertex [H->HeapArray [0].V] = 0;
    
    heapify (H, 0);
    
    return MinVertexNode;
}

static void decreaseKey(HEAP * H, int i, int DecreasedWeight)
{
    H->HeapArray [i].WeightOfAssociatedEdge = DecreasedWeight;
    
    int ChildIndex = i;
    int IsChildIndexZero = ChildIndex == 0;
    int ParentIndex = (ChildIndex - 1) / 2;
    
    int ChildWeight = H->HeapArray [ChildIndex].WeightOfAssociatedEdge;
    int ParentWeight = H->HeapArray [ParentIndex].WeightOfAssociatedEdge;
    
    while (! IsChildIndexZero && ChildWeight < ParentWeight)
    {
        swapVertexNodes (&H->HeapArray [ChildIndex], &H->HeapArray [ParentIndex]);
        swapIndices (&IndexOfVertex [H->HeapArray [ChildIndex].V], &IndexOfVertex [H->HeapArray [ParentIndex].V]);
        
        ChildIndex = ParentIndex;
        IsChildIndexZero = ChildIndex == 0;
        ParentIndex = (ChildIndex - 1) / 2;
        
        ChildWeight = H->HeapArray [ChildIndex].WeightOfAssociatedEdge;
        ParentWeight = H->HeapArray [ParentIndex].WeightOfAssociatedEdge;
    }
}

//MARK:-

static void getSourceVertex (int * SourceVertex)
{
    printf ("Enter source vertex:");
    scanf ("%d", SourceVertex);
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

static void displayMST (int ParentAndWeightOfVertex [2][MAX], int V)
{
    int SumOfMST = 0;
    printf("The following edges are in Prims MST\n");
    
    for (int j = 0; j < V; j++)
    {
        if(ParentAndWeightOfVertex [PARENT_OF][j] != -1)
        {
            printf ("%d to %d with weight %d\n", j, ParentAndWeightOfVertex[0][j] ,ParentAndWeightOfVertex [1][j]);
            
            SumOfMST += ParentAndWeightOfVertex [WEIGHT_OF][j];
        }
    }
    printf("Minimum cost spanning Tree is %d\n",SumOfMST);
}

static void initializeParentOfVertices (int ParentOfVertex [2][100])
{
    for(int i = 0; i < MAX; i++)
        ParentOfVertex [PARENT_OF][i] = -1;
}

static void fillHeapWithVertexData (HEAP * H, int V)
{
    for (int i = 0; i < V; i++)
    {
        VERTEX MinWeightVertexData;
        MinWeightVertexData.V = i;
        MinWeightVertexData.WeightOfAssociatedEdge = INT_MAX;
        
        insertKey (H,MinWeightVertexData);
        
        IsVertexAvailable [i] = 1;
        IndexOfVertex [i] = i;
    }
}

static void performRelaxation (NODE * AdjacentVertexNode, HEAP * H, int MinWeightVertex, int ParentAndWeightOfVertex [2][100])
{
    VERTEX AdjacentVertexData = AdjacentVertexNode->VertexData;
    int AdjacentVertex = AdjacentVertexData.V;
    int AdjacentVertexWeight = AdjacentVertexData.WeightOfAssociatedEdge;
    
    int IndexOfAdjacentVertex = IndexOfVertex [AdjacentVertex];
    
    int NewDistance = AdjacentVertexWeight;
    int CurrentDistance = H->HeapArray[IndexOfAdjacentVertex].WeightOfAssociatedEdge;
    
    if(IsVertexAvailable [AdjacentVertex] && NewDistance < CurrentDistance)
    {
        decreaseKey (H, IndexOfAdjacentVertex, NewDistance);
        
        ParentAndWeightOfVertex [PARENT_OF][AdjacentVertex] = MinWeightVertex;
        ParentAndWeightOfVertex [WEIGHT_OF][AdjacentVertex] = NewDistance;
    }
}

static void primAlgorithm (GRAPH G [], int V, int SourceVertex)
{
    int ParentAndWeightOfVertex [2][MAX];
    initializeParentOfVertices (ParentAndWeightOfVertex);
    
    HEAP H;
    initHeap (&H);
    fillHeapWithVertexData (&H, V);

    decreaseKey(&H, IndexOfVertex[SourceVertex],0);
    
    while (!isEmpty (&H))
    {
        VERTEX MinWeightVertexData = extractMin (&H);
        int MinWeightVertex = MinWeightVertexData.V;
        
        NODE * AdjacentVertexNode = G [MinWeightVertex].FirstNode;

        while(AdjacentVertexNode)
        {
            performRelaxation (AdjacentVertexNode, &H, MinWeightVertex, ParentAndWeightOfVertex);
            AdjacentVertexNode = AdjacentVertexNode->next;
        }
    }
    displayMST (ParentAndWeightOfVertex, V);
}

//MARK:-

int main (int ArgC, const char * ArgV [])
{
    GRAPH G [MAX];
    initGraph(G);
    
    int V;
    printf("Enter number of vertices:");
    scanf("%d",&V);
    
    for (int i = 0; i < V; i++)
    {
        int E;
        printf("Enter number of edges from vertex %d:", i);
        scanf("%d", &E);
        
        for(int j = 0; j < E; j++)
        {
            int AdjacentVertex;
            getAdjacentVertex (&AdjacentVertex);
            
            int WeightOfEdge;
            getWeightOfEdge (&WeightOfEdge);
            
            addEdge(G, i, AdjacentVertex, WeightOfEdge);
        }
    }
    int SourceVertex;
    getSourceVertex(&SourceVertex);
    
    primAlgorithm (G, V, SourceVertex);
    
    deleteGraph (G);
    return 0;
}

