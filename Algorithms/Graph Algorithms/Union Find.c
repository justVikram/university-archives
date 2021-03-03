#include <stdio.h>

#define MAX 100

/* Index of the array represents the actual element, and array [index] represents the set number the element belongs to */

int set [100];

int find (int element)
{
    return set [element];
}

void unionOfTwoSets_Naive (int ElementA, int ElementB)
{
    int SetNumberOfA = set [ElementA];
    int SetNumberOfB = set [ElementB];
    
    for (int i = 0; i < 100; i++)
    {
        if (set [i] == SetNumberOfA)  // Find all elements in subset A, and then overwrite their set numbers with that of subset B
            set [i] = SetNumberOfB;
    }
}

//MARK:-

typedef struct subset
{
    int parent;
    int rank;
}
SUBSET;

SUBSET S [100];

void initSubset ()
{
    for (int i = 0; i < MAX; i++)
    {
        S [i].parent = i;
        S [i].rank = 0;
    }
}

int findByPathCompression (int element)
{
    if(S [element].parent != element)
        S [element].parent = findByPathCompression (S [element].parent);

    return S [element].parent;
}

int getRank (int element)
{
    return S [element].rank;
}

void incrementRank (int ParentOfElement)
{
    S [ParentOfElement].rank++;
}

void updateParent (int CurrentParent, int NewParent)
{
    S [CurrentParent].parent = NewParent;
}

static void unionByRank (int ElementA, int ElementB)
{
    int ParentOfA = findByPathCompression (ElementA);
    int ParentOfB = findByPathCompression (ElementB);
    
    if(ParentOfA != ParentOfB)
    {
        if(getRank (ParentOfA) < getRank (ParentOfB))
            updateParent(ParentOfA, ParentOfB);

        else if (getRank (ParentOfB) < getRank (ParentOfA))
            updateParent(ParentOfB, ParentOfA);

        else
        {
            updateParent (ParentOfB, ParentOfA);
            incrementRank (ParentOfA);
        }
    }
}

int main (int argC, const char * argV [])
{
    initSubset ();
    
    unionByRank (0, 1);
    unionByRank (0, 3);
    unionByRank (4, 5);
    unionByRank (0, 5);
    printf ("Rank of 4: %d\n", findByPathCompression (4));
    
    return 0;
}
