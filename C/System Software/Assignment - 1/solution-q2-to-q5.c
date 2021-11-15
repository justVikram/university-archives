#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct input
{
    char label[10];
    char opcode[10];
    char oprand[10];
    int ad;
} store[22];

int main()
{
    char chr1;
    int col = 0, index = 0, ind = 0, indo = 1000;
    FILE *fileptr1 = fopen("/Users/avikram/Developer/C/System Software/assignment-one/SIC_input.txt", "r");
    FILE *fileptr2 = fopen("/Users/avikram/Developer/C/System Software/assignment-one/SIC_output.txt", "w");
    FILE *fileptr3 = fopen("/Users/avikram/Developer/C/System Software/assignment-one/SIC_symbol.txt", "w");
    chr1 = getc(fileptr1);
    printf("Reading from input file and storing in structure...");

    while (chr1 != EOF)
    {
        if (chr1 == '\n')
        {
            col = 0;
            index++;
            ind = 0;
        }

        else if (chr1 == ' ')
        {
            col++;
            ind = 0;
        }

        else
        {
            if (col == 0)
            {
                store[index].label[ind] = chr1;
                ind++;
            }
            else if (col == 1)
            {
                store[index].opcode[ind] = chr1;
                ind++;
            }
            else
            {
                store[index].oprand[ind] = chr1;
                ind++;
            }
        }

        chr1 = getc(fileptr1);
    }
    printf("\nStored in structure :) \n");

    printf("Generating SIC_Output.txt and SIC_Symbol.txt file...");
    for (int i = 0; i < 22; i++)
    {
        fprintf(fileptr2, "%d %s %s %s\n", indo, store[i].label, store[i].opcode, store[i].oprand);
        fprintf(fileptr3, "%d\t%s\n", indo, store[i].label);
        indo += 3;
    }
    printf("Done!");

    return 0;
}
