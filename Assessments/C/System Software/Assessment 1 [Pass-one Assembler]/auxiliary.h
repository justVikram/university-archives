#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct INPUT_FILE
{
    char label[100];
    char opcode[100];
    char operand[100];
}INPUT;

typedef struct SYMBOL_TABLE
{
    char label[100];
    int address;
}SYMTAB;

char label[50], opcode[50], operand[50];
char symbol[50];
char value[10];
char mnemonic[50];
int length;

int searchSymtab()
{
    FILE *fp4 = fopen("SYMTAB.txt", "r");
    int found = 0;

    while (!feof(fp4))
    {
        fscanf(fp4, "%s\t%s", symbol, value);
        if (strcmp(symbol, label) == 0)
        {
            found = 1;
            break;
        }
        fscanf(fp4, "%s\t%s", symbol, value);
    }

    fclose(fp4);
    return found;
}

int searchOptab()
{
    //! READ OPTAB
    FILE *fp5 = fopen("OPTAB.txt", "r");
    if (fp5 == NULL)
        printf("Error opening Optab.txt");

    int found = 0;
    while (!feof(fp5))
    {
        fscanf(fp5, "%s\t%s", mnemonic, value);
        if (strcmp(mnemonic, opcode) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(fp5);
    return found;
}

void one_pass_assembler()
{
    char delimit[] = " \t\r\n";
    int locctr, start;
    char line[100];
    size_t len = 100 * sizeof(char);
    locctr = 4096;

    //! READ INPUT FILE
    FILE *fp1 = fopen("SIC_INPUT.txt", "r");
    if (fp1 == NULL)
        exit(EXIT_FAILURE);

    FILE *fp2, *fp3, *fp4;

    //! CREATE BLANK SYMBOL TABLE
    fp2 = fopen("SYMTAB.txt", "w");

    //! CREATE BLANK INTERMDIATE FILE
    fp3 = fopen("INTERMEDIATE.txt", "w");
    fclose(fp2);

    //! READ INPUT FILE
    while ((fgets(line, len, fp1)) != NULL)
    {
        int len = 0;
        strcpy(label, " ");
        strcpy(opcode, " ");
        strcpy(operand, " ");

        //! USING STRTOK()
        char *p = strtok(line, delimit);
        char *array[4];

        while (p != NULL)
        {
            array[len++] = p;
            p = strtok(NULL, delimit);
        }

        if (len == 1)
        {
            if (*array[0] != '.')
                strcpy(opcode, array[0]);
        }
        else if (len == 2)
        {
            if (*array[0] != '.')
            {
                strcpy(opcode, array[0]);
                strcpy(operand, array[1]);
            }
        }
        else if (len == 3)
        {
            if (*array[0] != '.')
            {
                strcpy(label, array[0]);
                strcpy(opcode, array[1]);
                strcpy(operand, array[2]);
            }
        }
        // if (strcmp(opcode, "END") == 0)
        //     break;

        

        if (strcmp(opcode, "START") == 0)
        {
            start = (int)strtol(operand, NULL, 16);
            locctr = start;
            fprintf(fp3, "%x\t%s\t%s\t%s\n", locctr, label, opcode, operand);
            continue;
        }

        if ((!(strcmp(label, " ") == 0)) || (!(strcmp(opcode, " ") == 0)) || (!(strcmp(operand, " ") == 0)))
        {

            fprintf(fp3, "%x\t%s\t%s\t%s\n", locctr, label, opcode, operand);

            if (strcmp(label, " ") != 0)
                if (!searchSymtab())
                {
                    fp2 = fopen("SYMTAB.txt", "a");
                    fprintf(fp2, "%s\t%x\n", label, locctr);
                    fclose(fp2);
                }
                else
                {
                    printf("ERROR - Duplicate Symbol detected: %s\n", label);
                }

            if (searchOptab())
                locctr += 3;

            else if (strcmp(opcode, "WORD") == 0)
            {
                locctr += 3;
            }

            else if (strcmp(opcode, "RESW") == 0)
            {
                locctr += 3 * atoi(operand);
            }
            else if (strcmp(opcode, "RESB") == 0)
            {
                locctr += 1 * atoi(operand);
            }
            else if (strcmp(opcode, "BYTE") == 0)
            {
                if (operand[0] == 'C' || operand[0] == 'c')
                    locctr += (strlen(operand) - 3);
                else
                    locctr += floor((strlen(operand) - 3) / 2);
            }
            
            else if (strcmp(opcode, "END") == 0)
            {
                break;
            }

            else if (strcmp(opcode, "SIC") == 0)
            {
                continue;
            }

            else
            {
                printf("ERROR - Invalid Opcode detected: %s\n", opcode);
            }
        }
    }

    if (!(strcmp(opcode, "END") == 0))
        fprintf(fp3, " \t%s\t%s\t%s\n", label, opcode, operand);

    length = locctr - start;
    printf("\nLength of the code = %d bytes\n", length);

    fclose(fp1);
    fclose(fp3);
}

void show_intermediate_file()
{
    FILE *fp6 = fopen("INTERMEDIATE.txt", "r");

    if (fp6 == NULL)
        printf("Couldn't open INTERMEDIATE.txt\n");

    printf("\nShowing contents of INTERMEDIATE.txt...\n");

    char line[100];
    size_t len = 100 * sizeof(char);

    while ((fgets(line, len, fp6)) != NULL)
        printf("%s", line);

    fclose(fp6);
}

void show_symtab()
{
    FILE *fp7 = fopen("SYMTAB.txt", "r");
    if (fp7 == NULL)
        printf("Error Opening symtab.txt\n");

    printf("\nShowing contents of SYMTAB.txt...\n");

    fscanf(fp7, "%s\t%s", symbol, value);
    while (!feof(fp7))
    {
        printf("%s\t%s\n", symbol, value);
        fscanf(fp7, "%s\t%s", symbol, value);
    }

    fclose(fp7);
}