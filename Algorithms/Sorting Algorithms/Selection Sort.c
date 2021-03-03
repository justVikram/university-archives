#include <stdio.h>

void swapTwoNumbers (int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void sort_Selection (int* a, int N)
{
    int minIndex = 0;
    
    for (int i = 0; i < N - 1; i++)
    {
        minIndex = i;
        
        for (int j = i + 1; j < N; j++)  //Searching on the right side of index 'i'
        {
            if ( *(a + j) < *(a + minIndex))  //Checking if there is any element smaller than the one at index = minIndex
                minIndex = j;  //If yes, then updating the value of minIndex
        }
        swapTwoNumbers ((a + i), (a + minIndex));  //Swapping the element at 'i'th index with the one at updated minIndex location
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
    readArray(a, N);
    sort_Selection(a, N);
    displayArray(a, N);
}
