#include "monty.h"
void free_fxn(stack_t *container);
/**
 * print_char - this function print character at the top of the stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void print_char(stack_t **containter, unsigned int digit)
{
    if ((*containter) == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", digit);
        free_fxn(*containter);
        exit(EXIT_FAILURE);
    }
    if ((*containter)->n < 0)
    {
        if ((*containter)->n > 127)
        {
            fprintf(stderr, "L%d: can't pchar, value out of range\n", digit);
            free_fxn(*containter);
        }
    }
    printf("%d", (*containter)->n);
}