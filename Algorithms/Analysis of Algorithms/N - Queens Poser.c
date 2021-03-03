#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 4

void printSolution (int board [][size], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            printf ("%d\t", board[i][j]);
        
        printf ("\n");
    }
}

int isSafe (int board[][size], int R, int C)
{
    int i, j;
    
    for (j = 0; j < C; j++)  // Check all columns
    {
        if (board [R][j])
            return 0;
    }
    
    for (i = R + 1, j = C - 1; (i < size) && (j >= 0); i++, j--) //Bottom left diagonal
    {
        if (board [i][j])
            return 0;
    }
    
    for (i = R - 1, j = C - 1; (i >= 0) && (j >= 0); i--, j--)  //Upper left diagonal
    {
        if (board[i][j])
            return 0;
    }
    return 1;
}

int _NQueensPoser (int board [][size], int N, int C)    //C -> Column number
{
    if (C == N)
    {
        printSolution (board, size, size);
        return 1;
    }
    
    for (int R = 0; R < N; R++)     //R -> Row number
    {
        if (isSafe (board, R, C))
        {
            board [R][C] = 1;
            
            if (! _NQueensPoser(board, N, C + 1))  //Go to the next column
                board [R][C] = 0;    //Backtracking
            
            else
                return 1;
        }
    }
    return 0;
}

int NQueensPoser (int board [][size], int N)
{
    return _NQueensPoser (board, N, 0);
}

int main()
{
    int board [size][size] = {0};
    
    if (! NQueensPoser (board, size))
        printf ("INVALID - No solution exists\n");
    
    else
        printf ("Solution has been printed\n");
}
