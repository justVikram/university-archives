
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define THRESHOLD 0.7

int numberOfKeys = 0;
int TS = 5;

void addKey (int**, int);

void initHashTable (int *h)
{
    for (int i = 0; i < TS; i++)
        *(h + i) = INT_MAX;
}

int hash (int key)
{
    return key % TS;
}

double loadFactor ()
{
    return (double) numberOfKeys / TS;
}

void rehash (int** h)
{
    printf ("Rehashing table --rehashed\n");
    int previousTS = TS;
    TS = 2 * TS + 1;
    
    int* p = (int*) malloc (sizeof (int) * TS);
    initHashTable (p);
    numberOfKeys = 0;
    
    for (int i = 0; i < previousTS; i++)
    {
        if (*(*h + i) != INT_MAX)
            addKey(&p, *(*h + i));
    }
    free (*h);
    *h = p;
}

void addKey (int** h, int key)
{
    if (! *h)
    {
        *h = (int *) malloc (sizeof (int) * TS);
        initHashTable (*h);  //Since *h is an array of integers, it will be passed by reference, duPoint not needed
    }
    int index = hash (key);
    int *p = *h;
 
    while (*(p + index) != INT_MAX)
        index = (index + 1) % TS;
    
    *(p + index) = key;
    numberOfKeys++;
    
    if (loadFactor () >= THRESHOLD)
        rehash (h);
}

int searchKey (int* h, int key)
{
    int index = hash (key);
    
    while (*(h + index) != key && *(h + index) != INT_MAX)
        index = (index + 1) % TS;
    
    return *(h +index) == key;
}

int deleteKey (int* h, int key)
{
    if (! h)
        return 0;
    
    if (! searchKey (h, key))
        return 0;
    
    int index = hash (key);
    
    while (*(h + index) != key)
        index = (index + 1) % TS;
    
    *(h + index) = INT_MAX;
    numberOfKeys--;
    return 1;
}

void displayHashTable (int* h)
{
    if (! h)
    {
        printf ("No elements to display\n");
        return;
    }
    
    for (int i = 0; i < TS; i++)
    {
        if (*(h + i) == INT_MAX)
            printf ("EMPTY\n");
        
        else
            printf ("%d\n", *(h + i));
    }
}

void deleteHashTable (int** h)
{
    if (*h)
    {
        free (*h);
        *h = NULL;
    }
}

int main ()
{
    int* h = NULL;
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
                        addKey (&h, key);  //Since h may point to a new location altogether if table is rehashed, use duPoint
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
                        deleteHashTable (&h);
                        break;
                }
            }
        }
