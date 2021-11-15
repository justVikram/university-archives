#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{

    const char *delimiter_characters = " ";
    const char *filename = "/Users/avikram/Developer/C/System Software/assignment-one/solution-q1.c";
    FILE *input_file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    char *last_token;

    if (input_file == NULL)
        fprintf(stderr, "Unable to open file %s\n", filename);

    else
    {

        // Read each line into the buffer
        while (fgets(buffer, BUFFER_SIZE, input_file) != NULL)
        {

            // Write the line to stdout
            //fputs( buffer, stdout );

            // Gets each token as a string and prints it
            last_token = strtok(buffer, delimiter_characters);
            while (last_token != NULL)
            {
                printf("%s\n", last_token);
                last_token = strtok(NULL, delimiter_characters);
            }
        }

        if (ferror(input_file))
            perror("The following error occurred");

        fclose(input_file);
    }

    return 0;
}
