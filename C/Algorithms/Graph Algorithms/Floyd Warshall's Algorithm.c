#include <stdio.h>
#include <stdlib.h>

static void floydWarshallAlgorithm (int DistanceFromVertex [][10], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                int DirectDistance = DistanceFromVertex [i][j];
                int DistanceViaAuxVertex = DistanceFromVertex [i][k] + DistanceFromVertex [k][j];
                
                if (DirectDistance > DistanceViaAuxVertex)
                    DistanceFromVertex [i][j] = DistanceViaAuxVertex;
            }
        }
    }
}
