#include <stdio.h>
#include <string.h>

void isStringMatching (char* text, char* pattern)
{
    int i = 0;
    int j = 0;
    unsigned long int PatternLength = strlen (pattern);
    unsigned long int TextLength = strlen (text);
    
    for ( ; i < (TextLength - PatternLength); i++)
    {
        for (j = 0; j < PatternLength; j++)
        {
            if (*(text + i + j) != *(pattern + j))
                break;
        }
        if (j == PatternLength)
            printf ("Pattern found at index = %d\n", i);
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
    isStringMatching (text, pattern);
}
