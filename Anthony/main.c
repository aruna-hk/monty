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
<<<<<<< HEAD
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_file = fopen(argv[1], "r");
=======
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
>>>>>>> 47b6257474e52780db25bcc30e78717665c5eeb0

    if (my_file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

<<<<<<< HEAD
    char *my_opcode;
    char *my_arg;
    int iterator = 0;
    ssize_t line_of_characters = 1;
    char *storage = NULL;
    size_t length_of_file = 0;

    while (line_of_characters > 0)
=======
    while (fgets(storage, sizeof(storage), my_file) != NULL)
>>>>>>> 47b6257474e52780db25bcc30e78717665c5eeb0
    {
        iterator++;
<<<<<<< HEAD

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
=======
        my_opcode = strtok(storage, "\t\n\r");
        my_arg = strtok(NULL, "\t\n\r");
>>>>>>> 47b6257474e52780db25bcc30e78717665c5eeb0

        if (my_opcode != NULL)
        {
            exec_fxn(my_opcode, my_arg, iterator, &stack);
        }
    }
    
    fclose(my_file);
    return 0;
}
