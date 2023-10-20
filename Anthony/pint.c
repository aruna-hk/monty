#include "monty.h"
void free_fxn(stack_t *container);
/**
 * pint_point - this function print values at the top of the stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void pint_point(stack_t **container, unsigned int digit)
{
    if (*container == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", digit);
        free_fxn(*container);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*container)->n);
}