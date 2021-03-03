#include <stdio.h>
#include <string.h>

void swap (char *c1, char *c2)
{
    char temp;
    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

void _permuteString (char *str, int L, unsigned long int U)
{
    if (L >= U)
    {
        printf ("%s\n", str);
        return;
    }
    
    for (int i = L; i <= U; i++)
    {
        swap (str + i, str + L);
        _permuteString (str, L + 1, U);
        swap (str + i, str + i);
    }
}

void permuteString (char *str)
{
    _permuteString (str, 0, strlen(str) - 1);
}

int main ()
{
    char str [10];
    printf ("Enter string:");
    scanf ("%s", str);
    permuteString (str);
}
