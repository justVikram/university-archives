#include <stdio.h>

void swapTwoNumbers (int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void sort_Insertion (int* a, int N)
{
    for (int i = 1; i < N; i++)
    {
        int j = i - 1;  // Starting from index = 1 so comparision with index = 0 can be made
        int key = *(a + i);
        
        while (j >= 0 && key < *(a + j))  //Shift a [j]  to to index j + 1
        {
            *(a + j + 1) = *(a + j);
            j--;
        }
        *(a + j + 1) = key;
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
    sort_Insertion(a, N);
    displayArray(a, N);
}
