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

void displayList (n* head, int i)
{
    printf ("At index = %d,\n", i);
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
    
    else
        printf ("EMPTY\n");
}

void displayHashTable (n** h)
{
    for (int i = 0; i < TS; i++)
        displayList (*(h + i), i);
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

int doesLoopExist (n* head)
{
    n* h [TS];
    initHashTable (h);
    n* p = head;
    
    while (p)
    {
        if (! searchKey(h, (int) p))  //Typecast to int
            addKey (h, (int) p);
        
        else
        {
            deleteHashTable (h);
            return 1;
        }
        p = p->next;
    }
    deleteHashTable (h);
    return 0;
}

