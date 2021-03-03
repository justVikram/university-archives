#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INFINITY INT_MAX

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

static void initGraph (GRAPH G[])
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

static void deleteGraph (GRAPH G [])
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


static void initializeDistancesFromSource (int * DistanceFromSource, int SourceVertex)
{
    for (int i = 0; i < MAX; i++)
        DistanceFromSource [i] = INT_MAX;
    
    DistanceFromSource [SourceVertex] = 0;
}

static void performRelaxation (GRAPH G [], int DistanceFromSource [], int V)
{
    for (int j = 0; j < V; j++)
    {
        NODE * AdjacentVertexNode = G [j].FirstNode;
        
        while (AdjacentVertexNode)
        {
            int OriginVertex = j;
            
            VERTEX AdjacentVertexData = AdjacentVertexNode->VertexData;
            int AdjacentVertex = AdjacentVertexData.V;
            
            int DistanceToOriginVertex = DistanceFromSource [OriginVertex];
            int DistanceFromOriginVertex = AdjacentVertexData.WeightOfAssociatedEdge;
            
            int EffectiveDistance = DistanceToOriginVertex + DistanceFromOriginVertex;
            int OriginalDistance = DistanceFromSource [AdjacentVertex];
            
            
            if (DistanceToOriginVertex != INFINITY && EffectiveDistance < OriginalDistance)
                DistanceFromSource [AdjacentVertex] = EffectiveDistance;
            
            AdjacentVertexNode = AdjacentVertexNode->next;
        }
    }
}

static int detectNegativeEdgeCycle (GRAPH G [], int DistanceFromSource [], int V)
{
    for (int j = 0; j < V; j++)
    {
        NODE * AdjacentVertexNode = G [j].FirstNode;
        
        while (AdjacentVertexNode)
        {
            int OriginVertex = j;
            
            VERTEX AdjacentVertexData = AdjacentVertexNode->VertexData;
            int AdjacentVertex = AdjacentVertexData.V;
            
            int DistanceToOriginVertex = DistanceFromSource [OriginVertex];
            int DistanceFromOriginVertex = AdjacentVertexData.WeightOfAssociatedEdge;
            
            int EffectiveDistance = DistanceToOriginVertex + DistanceFromOriginVertex;
            int OriginalDistance = DistanceFromSource [AdjacentVertex];
            
            if (DistanceToOriginVertex != INFINITY && EffectiveDistance < OriginalDistance)
                return 1;
            
            AdjacentVertexNode = AdjacentVertexNode->next;
        }
    }
    return 0;
}

static int bellmanFordAlgorithm (GRAPH G [], int V, int SourceVertex)
{
    int DistanceFromSource [MAX];
    
    initializeDistancesFromSource (DistanceFromSource, SourceVertex);

    for (int i = 1; i < V; i++)
        performRelaxation (G, DistanceFromSource, V);

    int IsThereNegativeEdgeCycle = detectNegativeEdgeCycle (G, DistanceFromSource, V);
    
    if (IsThereNegativeEdgeCycle)
        return 0;
    
    else
    {
        getShortestPathsFromSource (DistanceFromSource, V, SourceVertex);
        return 1;
    }
}


int main (int argC, const char * argV [])
{
    GRAPH G [MAX];
    initGraph(G);
    
    int V;
    printf("Enter number of vertices:");
    scanf("%d",&V);
    
    for (int i = 0; i < V; i++)
    {
        int E;
        printf("Enter number of edges from source %d: ", i);
        scanf("%d", &E);
        
        for(int j = 0; j < E; j++)
        {
            int AdjacentVertex;
            printf("Enter adjacent vertex:");
            scanf("%d",&AdjacentVertex);
            
            int WeightOfEdge;
            printf("Enter weight:");
            scanf("%d", &WeightOfEdge);
            
            addEdge(G, i, AdjacentVertex, WeightOfEdge);
        }
    }
    
    int SourceVertex;
    printf("Enter source:");
    scanf("%d",&SourceVertex);

    int IsSuccessful = bellmanFordAlgorithm(G, V, SourceVertex);
    
    if(! IsSuccessful)
        printf("Negative weight Cycle Exists\n");
    
    deleteGraph(G);
    return 0;

}

