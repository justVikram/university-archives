#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void constructLPS (char* pattern, int* LPS)
{
    unsigned long int m = strlen (pattern);
    LPS [0] = 0;
    int i = 1;
    int LoPES = 0;  //Length of prefix which is equal to suffix
    
    while (i < m)
    {
        if (pattern [i] == pattern [LoPES])
        {
            LoPES++;
            LPS [i] = LoPES;
            i++;
        }
        else
        {
            if (! LoPES)
            {
                LPS [i] = 0;
                i++;
            }
            else
                LoPES = LPS [LoPES - 1];
        }
    }
}

void isStringMatching_KMP (char* text, char* pattern)
{
    unsigned long int LP = strlen (pattern);
    unsigned long int LT = strlen (text);
    int* LPS = (int*) malloc (sizeof (int) * LP);
    constructLPS (pattern, LPS);
    int i = 0; int j = 0;
    
    while (i < LT)
    {
        if (text [i] == pattern [j])
        {
            i++;
            j++;
        }
        if (j == LP)
        {
            printf ("Pattern found at index %d\n", i - j);
            j = LPS [j - 1];
        }
        
        else if (text [i] != pattern [j])
        {
            if (j)
                j = LPS [j - 1];
            
            else
                i++;
        }
    }
}

void getString (char* string)
{
    scanf ("%s", string);
}

int main ()
{
    char text [50];
    char pattern [50];
    printf ("Enter text:");
    getString (text);
    printf ("Enter pattern:");
    getString (pattern);
    isStringMatching_KMP (text, pattern);
}
