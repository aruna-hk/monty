#include "monty.h"
#include <string.h>
void exec_fxn(char *opcode, char * my_argument, unsigned int digit, stack_t **stack);
/**
 * main - this program is based on tdesigning the interpreter
 * @argc: this is the number of the input value
 * @argv: this are the array of pointer
 * Return: success(0)
*/
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_file = fopen(argv[1], "r");

    if (my_file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *my_opcode;
    char *my_arg;
    int iterator = 0;
    ssize_t line_of_characters = 1;
    char *storage = NULL;
    size_t length_of_file = 0;

    while (line_of_characters > 0)
    {
        line_of_characters = getline(&storage, &length_of_file, my_file);
        iterator++;

        if (line_of_characters > 0)
        {
            my_opcode = strtok(storage, "\t\n\r");
            my_arg = strtok(NULL, "\t\n\r");

            if (my_opcode != NULL)
            {
                exec_fxn(my_opcode, my_arg, iterator, &stack);
            }
        }
    }

    free(storage);
    fclose(my_file);
    return 0;
}
