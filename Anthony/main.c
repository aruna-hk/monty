#include "monty.h"
#include <string.h>
#include <stdio.h>
stack_t *stack = NULL;
void exec_fxn(char *opcode, char *my_argument, unsigned int digit, stack_t **stack);
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char **argv)
{
    char *my_opcode;
    char *my_arg;
    int iterator = 0;
    char storage[1024];
    FILE *my_file;

    if (argc < 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    my_file = fopen(argv[1], "r");
    if (my_file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(storage, sizeof(storage), my_file) != NULL)
    {
        iterator++;
        my_opcode = strtok(storage, "\t\n\r");
        my_arg = strtok(NULL, "\t\n\r");

        if (my_opcode != NULL)
        {
		exec_fxn(my_opcode, my_arg, iterator, &stack);
        }

    }
    
    fclose(my_file);
    return 0;
}
