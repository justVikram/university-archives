#include<stdio.h>
#include<string.h>
#include<ctype.h>

char firstRepeatedChar (char str[])  // O (n)
{
    int a [26] = {0};
    char ch;
    int index;
    
    for (int i = 0; str [i]; i++)
    {
        ch = tolower (str [i]);
        index = ch - 97;
        a[index]++;
        
        if (a[index] > 1)
            return ch = index + 97;
    }
    return '0';
}

int FirstRepeatedChar (char str[])  // O (n^2)
{
    int ch = -1;
    unsigned long int length = strlen (str) - 1, i, j;
    
    for (i = length; i >= 0; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (str [i] == str [j])
                ch = str [i];
        }
    }
    return ch;
}

int main ()
{
    char str[100];
    printf ("Enter string:");
    scanf ("%s", str);
    printf ("%c\n", toupper (firstRepeatedChar (str)));
}
