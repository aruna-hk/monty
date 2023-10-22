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
    char *my_opcode;
    char *my_arg;
    int iterator = 0;
    FILE *my_file;
    ssize_t length_of_file = 0;
    ssize_t line_of_characters = 1;
    char *storage = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "Error: no such a file\n");
        exit(EXIT_FAILURE);
    }
    
    my_file = fopen(argv[1], "r");
    
    if (my_file == NULL)
    {
        fprintf(stderr, "Error: cannot open such a file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    while (line_of_characters > 0)
    {
        line_of_characters = getline(&storage, &length_of_file, my_file);
        iterator++;
        my_opcode = strtok(storage, "\t\n\r");
        my_arg = strtok(NULL, "\t\n\r");
        exec_fxn(my_opcode, my_arg, iterator, &stack);
    }

    free(storage);
    fclose(my_file);
    return(0);
}
