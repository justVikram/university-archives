#include <stdio.h>

void swapTwoNumbers (int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void sort_Bubble (int* a, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (*(a + j) > *(a + j + 1))
                swapTwoNumbers ((a + j), (a + j + 1));
        }
    }
}

void readArray (int* a, int N)
{
    int i = 0;
    
    while (i < N)
        scanf ("%d", (a + i++));
}

void displayArray (int* a, int N)
{
    int i = 0;
    printf ("The sorted array is:\n");
    
    while (i < N)
        printf ("%d\t", *(a + i++));
    
    printf ("\n");
}

int main ()
{
    int a [50];
    int N;
    printf ("Enter size of array:");
    scanf ("%d", &N);
    printf ("Enter array elements to be sorted:\n");
    readArray (a, N);
    sort_Bubble (a, N);
    displayArray (a, N);
}
