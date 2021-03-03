#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

//MARK:-

typedef struct Heap
{
    int HeapArray [MAX];
    int SizeOfHeap;
}sh;


void initHeap (sh *Heap)
{
    Heap->SizeOfHeap = 0;
}

int isFull (const sh* Heap)
{
    return Heap->SizeOfHeap == MAX;
}

int isEmpty (const sh* Heap)
{
    return Heap->SizeOfHeap == 0;
}

void swap (int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//MARK:-

void insertKey (sh* Heap, int key)
{
    Heap->HeapArray [Heap->SizeOfHeap] = key;
    
    int ChildIndex = Heap->SizeOfHeap++;      //index of element last added
    int ParentIndex = (ChildIndex - 1) / 2;
    
    int IsChildSmallerThanParent = Heap->HeapArray [ChildIndex] < Heap->HeapArray [ParentIndex];

    while (ChildIndex != 0 && IsChildSmallerThanParent)
    {
        swap (&Heap->HeapArray [ChildIndex], &Heap ->HeapArray [ParentIndex]);
        
        ChildIndex = ParentIndex;        //The element now at parent index may not be satisfying heap property
        ParentIndex = (ChildIndex - 1) / 2;      //This method is used as we are heapifying the tree from bottom to top
        
        IsChildSmallerThanParent = Heap->HeapArray [ChildIndex] < Heap->HeapArray [ParentIndex];
    }
    
}

void displayHeap (const sh* Heap)
{
    for (int i = 0; i < Heap->SizeOfHeap; i++)
        printf (" index = %d | %d\n", i, *(Heap->HeapArray + i));
}

void heapify (sh* Heap, int i)      //i -> index | we use this to heapify the tree from top to bottom
{
    int LeftChildIndex = 2 * i + 1;
    int RightChildIndex = 2 * i + 2;
    int MinElementIndex = i;
    
    int IsLeftIndexValid = LeftChildIndex < Heap->SizeOfHeap;      //Could happen that there is no left child for some node, thus no left index
    int IsRightIndexValid = RightChildIndex < Heap->SizeOfHeap;
    
    int IsLeftChildSmaller = Heap->HeapArray [LeftChildIndex] < Heap->HeapArray [MinElementIndex];
    int IsRightChildSmaller = Heap->HeapArray [RightChildIndex] < Heap->HeapArray [MinElementIndex];
    
    if (IsLeftIndexValid && IsLeftChildSmaller)
        MinElementIndex = LeftChildIndex;
    
    if (IsRightIndexValid && IsRightChildSmaller)
        MinElementIndex = RightChildIndex;
    
    if (MinElementIndex != i)      //Heapify should be invoked only if the children are smaller when compared to the parent
    {                             //If the value of MinElementIndex remains unaltered, it means heapification is not needed
        swap(&Heap->HeapArray [i], &Heap->HeapArray [MinElementIndex]);
        heapify (Heap, MinElementIndex);      //After swapping, MinElementIndex no longer contains the min element, thus, heapify
    }
}

int extractMin (sh* Heap)
{
    int MinimumElement = Heap->HeapArray [0];
    int LastNodeIndex = Heap->SizeOfHeap-- - 1;      //Replace rooted element with last node's element
    Heap->HeapArray [0] = Heap->HeapArray [LastNodeIndex];
    heapify (Heap, 0);     //After assigning new value to index 0, heap may have to be re-heapified
    return MinimumElement;
}

void decreaseKey (sh* Heap, int key, int index)
{
    int IsIndexValid = index < Heap->SizeOfHeap;
    int IsKeyValid = key < Heap->HeapArray [index];
    
    if (IsIndexValid || IsKeyValid)
    {
        Heap->HeapArray [index] = key;
        int ParentIndex = (index - 1) / 2;
        int IsChildSmaller = Heap->HeapArray [index] < Heap->HeapArray [ParentIndex];
        int IsIndexZero = index == 0;
        
        while (! IsIndexZero && IsChildSmaller)
        {
            swap (&Heap->HeapArray [index], &Heap->HeapArray [ParentIndex]);
            
            index = ParentIndex;
            IsIndexZero = index == 0;
            ParentIndex = (index - 1) / 2;
        }
    }
    
}

int deleteKey (sh* Heap, int index)
{
    int IsIndexValid = index < Heap->SizeOfHeap;
    
    if (! IsIndexValid)
        return INT_MAX;
    
    int DeletedKey = Heap->HeapArray [index];
    decreaseKey (Heap, INT_MIN, index);
    extractMin (Heap);
    return DeletedKey;
}

//MARK:-

int main (int argc, char ** argv)
{
    sh Heap;
    initHeap (&Heap);
    int ch, key, index;
    
    while (1)
    {
        printf ("Enter choice:");
        scanf ("%d", &ch);
        
        switch (ch)
        {
            case 1:
                printf ("Insert key\n");
                
                if (isFull (&Heap))
                    printf ("ERROR -- Heap is full\n");
                
                else
                {
                    printf ("Enter element to be inserted:\n");
                    scanf ("%d", &key);
                    insertKey (&Heap, key);
                }
                break;
                
            case 2:
                printf ("Display heap\n");
                displayHeap (&Heap);
                
                break;
                
            case 3:
                printf ("Extracting min\n");
                
                if (isEmpty (&Heap))
                    printf ("ERROR -- Heap is empty\n");
                
                else
                    printf ("The min element is = %d\n", extractMin (&Heap));
                
                break;
                
            case 4:
                printf ("Decrease key\n");
                
                if (isEmpty(&Heap))
                    printf ("ERROR -- Heap is empty\n");
                
                else
                {
                    printf ("Enter new value:\n");
                    scanf ("%d", &key);
                    printf ("Enter index at which value must be updated:\n");
                    scanf ("%d", &index);
                    decreaseKey (&Heap, key, index);
                    printf ("Updation successful\n");
                }
                
                break;
                
            case 5:
                printf ("Delete key\n");
                
                if (isEmpty (&Heap))
                    printf ("ERROR -- Heap is empty\n");
                
                else
                {
                    printf ("Enter index at which value must be deleted:\n");
                    scanf ("%d", &index);
                    int DeletedKey = deleteKey(&Heap, index);
                    
                    if (DeletedKey == INT_MAX)
                        printf ("ERROR -- Invalid index\n");
                    else
                        printf ("The deleted key is = %d\n", DeletedKey);
                }
                
                break;
        }
    }
}
