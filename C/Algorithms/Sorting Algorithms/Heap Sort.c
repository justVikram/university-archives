#include <stdio.h>

void swapTwoNumbers (int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void heapify (int* a, int N, int i) //Max heap of size N
{
    int IndexOfMaxElement = i;
    int IndexOfChild_Left = 2 * i + 1;
    int IndexOfChild_Right = 2 * i + 2;
    
    if (IndexOfChild_Left < N  && *(a + IndexOfMaxElement) < *(a + IndexOfChild_Left))
        IndexOfMaxElement = IndexOfChild_Left;
    
    if (IndexOfChild_Right < N &&  *(a + IndexOfMaxElement) < *(a + IndexOfChild_Right))
        IndexOfMaxElement = IndexOfChild_Right;
    
    int WasIndexOfMaxElementUpdated = IndexOfMaxElement != i;
    
    if (WasIndexOfMaxElementUpdated)  //To avoid infinite recursion
    {
        swapTwoNumbers((a + IndexOfMaxElement), (a + i));
        heapify(a, N, IndexOfMaxElement);  //Check if heapify property is still met at index from where max element was swapped
    }
    
}

void sort_Heap (int* a, int N)
{
    int i = (N / 2) - 1;
    
    for ( ; i >= 0; i--)  //Creating max heap
        heapify (a, N, i);
    
    for (i = N - 1; i >= 0; i--)  //Sorting the array
    {
        swapTwoNumbers((a + i), a);  //Bring the greatest element to the end of the array
        heapify(a, i, 0);  //Check if heapify property is still met at index 0
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
    sort_Heap (a, N);
    displayArray (a, N);
}
