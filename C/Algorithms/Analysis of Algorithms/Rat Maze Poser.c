#include <stdio.h>
#include <stdlib.h>

void printMatrix (int matrix [][10], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            printf ("%d\t", matrix [i][j]);
        
        printf ("\n");
    }
}

void readMatrix (int matrix [][10], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j  = 0; j < C; j++)
            scanf ("%d", &matrix [i][j]);
    }
}

int isSafe (int maze [][10], int R, int C, int x, int y)
{
    int c;
    return c = ((x < R) && (y < C) && (maze [x][y])) ? 1 : 0;
}

int _solveMaze (int maze [][10], int R, int C, int x, int y, int sol [][10])  //x, y -> coordinates
{
    if ((x == R - 1) && (y == C - 1) && maze [x][y])
    {
        sol [x][y] = 1;
        printMatrix (sol, R, C);
        return 1;
    }
    
    if (isSafe(maze, R, C, x, y))
    {
        sol [x][y] = 1;
        
        if (! _solveMaze(maze, R, C, x, y + 1, sol))  //Check right
        {
            if (! _solveMaze(maze, R, C, x + 1, y, sol))  //Check down
                sol [x][y] = 0;
        }
        return 1;
    }
    return 0;
}

void solveMaze (int maze [][10], int R, int C)
{
    int sol [10][10] = {0};
    _solveMaze (maze, R, C, 0, 0, sol);  //Star with 0th row and 0th column, storing the answer in sol
}

int main ()
{
    int maze [10][10];
    int n;
    printf ("Enter order of square matrix:");
    scanf ("%d", &n);
    printf ("Enter values for maze matrix\n");
    readMatrix (maze, n,n);
    solveMaze (maze, n, n);
}
