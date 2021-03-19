#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swapTwoNumbers (int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partitionArray (int* a, int L, int U)
{
    int randomIndex = (rand () % (U - L + 1)) + L;  //Generates some random index value
    swapTwoNumbers ((a + randomIndex), (a + U));  //Swaps the last element with the one at random index
    int pivotedElement = *(a + U);  //Element at the last index is made the pivot
    int i = L - 1;  //Keeps count of elements lesser than or equal to pivot
    
    for (int j = L; j < U; j++)
    {
        if (*(a + j) < pivotedElement)
            swapTwoNumbers ((a + ++i), (a + j));  //Start putting elements < pivotedElement on the left side of the array
    }
    swapTwoNumbers ((a + ++i), (a + U));
    return i;
}

void _sort_Quick (int* a,int L, int U)
{
    if (L < U)
    {
        int pivotIndex = partitionArray (a, L, U);  // Returns index at which pivoted element is found
        _sort_Quick (a, L, pivotIndex - 1);
        _sort_Quick (a, pivotIndex + 1, U);
    }
}

void sort_Quick (int* a, int N)
{
    _sort_Quick (a, 0, N - 1);
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
    srand ((unsigned int) time (0));
    int a [50];
    int N;
    printf ("Enter size of array:");
    scanf ("%d", &N);
    printf ("Enter array elements to be sorted:\n");
    readArray (a, N);
    sort_Quick (a, N);
    displayArray (a, N);
}
