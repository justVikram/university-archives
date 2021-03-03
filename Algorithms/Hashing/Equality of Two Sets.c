#include <stdio.h>
#include <stdlib.h>
#define TS 11

typedef struct node
{
    int data;
    struct node* next;
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
    p->next = h [index];
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

int areSetsEqual (int* a, int m, int* b, int n)
{
    if (m != n)
        return 0;
    
    struct node* h [TS];
    initHashTable (h);
    
    int i = 0;
    while (i < m)
        addKey (h, *(a + i++));
    
    for (int j = 0; j < n; j++)
    {
        if (! searchKey (h, *(b + j++)))
        {
            deleteHashTable (h);
            return 0;
        }
    }
    deleteHashTable (h);
    return 1;
}

int main ()
{
    int a [100], b [100];
    int m, n;
    printf ("Enter number of elements in set A:");
    scanf ("%d", &m);
    printf ("Enter elements for set A:\n");
    inputArray (a, m);
    printf ("Enter number of elements in set B:");
    scanf ("%d", &n);
    printf ("Enter elements for set B:\n");
    inputArray (b, n);
    
    if (areSetsEqual (a, m, b, n))
            printf ("Sets are equal\n");
    
    else
        printf ("Sets are unequal\n");
}
