#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define TS 11

typedef struct node
{
    int data;
    struct node * next;
}n;

void initHashTable (n** h)
{
    for (int i = 0; i < TS; i++)
        *(h + i) = NULL;
}

int hash (int key)
{
    return key % TS;
}

void addKey (n** h, int key)
{
    n* p = (n*) malloc (sizeof (n));
    p->next = NULL;
    p->data = key;
    int index = hash (key);
    p->next = *(h + index);
    *(h + index) = p;
}

int searchKey (n** h, int key)
{
    int index = hash (key);
    n* cur = *(h + index);
    
    while (cur)
    {
        if (cur->data == key)
            return 1;
        
        cur = cur->next;
    }
    return 0;
}

int deleteKey (n** h, int key)
{
    int index = hash (key);
    n* cur = *(h + index);
    n* prev = NULL;
    
    while (cur && cur->data != key)
    {
        prev = cur;
        cur = cur->next;
    }
    
    if (cur)
    {
        if (! prev)
            *(h + index) = cur->next;
        
        else
        prev->next = cur->next;
        
        free (cur);
        return 1;
    }
    return 0;
}

void deleteList (n** head)
{
    n* cur = *head;
    n* prev = NULL;
    
    while (cur)
    {
        prev = cur;
        cur = cur->next;
        free (prev);
    }
    *head = NULL;
}

void deleteHashTable (n** h)
{
    for (int i = 0; i < TS; i++)
        deleteList ((h + i));
}

void displayList (n* head, int i)
{
    n* cur = head;
    
    if (cur)
    {
        while (cur)
           {
               printf ("%d\t", cur->data);
               cur = cur->next;
           }
        printf ("\n");
    }
}

void displayHashTable (n** h)
{
    for (int i = 0; i < TS; i++)
        displayList (*(h + i), i);
}

void inputArray (int* array, int size)
{
    int i = 0;
    
    while (i < size)
        scanf ("%d", (array + i++));
}

void removeDuplicates (int* a, int n)
{
    struct node* h [TS];
    initHashTable (h);
    
    for (int i = 0; i < n; i++)
    {
        if (! searchKey (h, *(a + i)))
            addKey (h, *(a + i));
    }
    printf ("Displaying array after removing duplicates:\n");
    displayHashTable (h);
    deleteHashTable (h);
}

int main ()
{
    int a [100];
    int n;
    printf ("Enter number of elements in set:");
    scanf ("%d", &n);
    printf ("Enter elements for set:\n");
    inputArray (a, n);
    removeDuplicates (a, n);
}
