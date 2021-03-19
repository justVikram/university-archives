#include <stdio.h>

void readArray (int *a, int N)
{
    int i = 0;
    
    while (i < N)
        scanf ("%d", a + i++);
}

void generateSubset (int *a, int N)
{
    int p = 1 << N;   //p = 2 ^ n
    
    for (int i = 0; i <  p; i++)   //Loop executes  2^n times
    {
        for (int k = 0; k < N; k++)   //Loop executes n times
        {
            if (i & (1 << k))
            {
                printf ("%d\t", a[k]);
            }
        }
        printf ("\n");
    }
}

int main ()
{
    int a[10];
    int N;
    printf ("Enter size\n");
    scanf ("%d", &N);
    printf ("Enter elements\n");
    readArray (a, N);
    generateSubset (a, N);
}
