#include <stdio.h>
#include <string.h>

void isStringMatching_boyerMoore (char* text, char* pattern)
{
    int BadCharTable [256];  //BCT of size 256
    
    for (int i = 0; i < 256; i++)
        BadCharTable [i] = -1;
    
    for (int i = 0; pattern [i]; i++)
        BadCharTable [pattern [i]] = i;
    
    long i = 0;
    long j;
    long LengthOfPattern = strlen (pattern);
    long LengthOfText = strlen (text);
    
    while (i <= LengthOfText - LengthOfPattern)
    {
        j = strlen (pattern) - 1;
        
        while ((j >= 0) && text [i + j] == pattern [j])
            j--;
        
        if (j < 0)
        {
            printf ("Pattern found at index = %ld\n", i);
            i = i + LengthOfPattern - BadCharTable [text [i]];
        }
        
        else
        {
            char BadCharacter = text [i + j];
            
            if (j - BadCharTable [BadCharacter] < 0)
                i++;
            
            else
                i = i + j - BadCharTable [BadCharacter];
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
    isStringMatching_boyerMoore (text, pattern);
}
