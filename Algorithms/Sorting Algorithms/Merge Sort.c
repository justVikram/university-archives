#include <stdio.h>

void mergeElements (int* a, int L, int midpoint, int U)
{
    int NumberOfElements_LHS = midpoint - L + 1;
    int NumberOfElements_RHS = U - midpoint;
    int SubArray_LHS [100];
    int SubArray_RHS [100];
    
    for (int i = 0; i < NumberOfElements_LHS; i++)  //Copying elements from LHS of 'a' to LHS sub array
        *(SubArray_LHS + i) = *(a + i + L);  //L will not always be 0
    
    for (int i = 0; i < NumberOfElements_RHS; i++)  //Copying elements from RHS of 'a' to RHS sub array
        *(SubArray_RHS + i) = *(a + i + midpoint + 1); //RHS of 'a' begins from (midpoint + 1)
    
    int i = 0;
    int j = 0;
    int k = L;  //Elements need to be written in resultant array from lower limit L
    
    while (i < NumberOfElements_LHS && j < NumberOfElements_RHS)
    {
        if (SubArray_LHS [i] < SubArray_RHS [j])
            a [k++] = SubArray_LHS [i++];
        
        else
            a [k++] = SubArray_RHS [j++];
    }
    
    while (i < NumberOfElements_LHS)
        a [k++] = SubArray_LHS [i++];
    
    while (j < NumberOfElements_RHS)
        a [k++] = SubArray_RHS [j++];
}

void _sort_Merge (int* a, int L, int U)
{
    if (L < U)
    {
        int midpoint = (L + U) / 2;
        _sort_Merge (a, L, midpoint);
        _sort_Merge (a, midpoint + 1, U);
        mergeElements (a, L, midpoint, U);
    }
    
}

void sort_Merge (int* a, int N)
{
    _sort_Merge (a, 0, N - 1);
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
    sort_Merge (a, N);
    displayArray (a, N);
}
