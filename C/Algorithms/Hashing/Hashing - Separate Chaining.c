#include <stdio.h>
#include <stdlib.h>
#define TS 11  // Table Size

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
    return key % TS;  //Hash function, it returns index where key should be stored
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

int main ()
{
    n *h [TS];
    initHashTable (h);  //Array, so automatically passed by address
    int ch, key;
    
    while (1)
    {
        printf ("Enter choice:");
        scanf ("%d", &ch);
        
        switch (ch)
        {
            case 1:
                printf ("Add key\n");
                printf ("Enter key:");
                scanf ("%d", &key);
                addKey (h, key);
                break;
                
            case 2:
                printf ("Search key\n");
                printf ("Enter key to be searched:");
                scanf ("%d", &key);
                
                if (searchKey (h, key))
                    printf ("Key was found\n");
                
                else
                    printf ("ERROR - Key could not be found\n");
                
                break;
                
            case 3:
                printf ("Delete key\n");
                printf ("Enter key:");
                scanf ("%d", &key);
                
                if (deleteKey (h, key))
                    printf ("Key was deleted\n");
                
                else
                    printf ("ERROR - Key could not be deleted\n");
                
                break;
                
            case 4:
                printf ("Display key \n");
                displayHashTable (h);
                
                break;
                
            case 5:
                printf ("Delete Hash Table --deleted\n");
                deleteHashTable (h);
                break;
        }
    }
}
