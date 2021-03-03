#include <stdio.h>
#include <string.h>

void isStringMatching_RabinKarp (char* text, char* pattern)
{
    unsigned long int LT = strlen (text);  //Length of text
    unsigned long int LP = strlen (pattern);  //Length of pattern
    int NC = 256;  //Number of characters
    int m = 101;  //modulo number value (any huge prime number)
    int HP = 0;  //Hash of pattern
    int HT = 0;  //Hash of text
    
    for (int i = 0; i < LP; i++)
    {
        HP = (HP * NC + pattern [i]) % m;
        HT = (HT * NC + text [i]) % m;
    }
    int x = 1;
    
    for (int i = 1; i <= LP - 1; i++)  //To compute NC ^ (LP - 1)
        x = (x * NC) % m;
    
    for (int i = 0; i <= LT - LP; i++)
    {
        if (HP == HT)
        {
            int j = 0;
            
            for ( ; j < LP; j++)
            {
                if (text [i + j] != pattern [j])
                    break;
            }
            if (j == LP)
                printf ("Pattern found @ index %d\n", i);
            
            else
                printf ("Pattern not found\n");
        }
        HT = (NC * (HT - text [i] * x) + text [i + LP]) % m;
        
        if (HT < 0)
            HT = HT + m;
    }
    
}

void getString (char* string)
{
    scanf ("%s", string);
}

int main ()
{
    char text [50];
    printf ("Enter text:");
    getString (text);
    
    char pattern [50];
    printf ("Enter pattern:");
    getString (pattern);
    
    isStringMatching_RabinKarp (text, pattern);
}
