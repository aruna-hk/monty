#include "monty.h"
void free_fxn(stack_t *container);
void pop_fxn(stack_t **containter, unsigned int digit);
/**
 * div_fxn - this function implement the division of value in stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void div_fxn(stack_t **container, unsigned int digit)
{
    if ((*container) == NULL)
    {
        if ((*container)->next == NULL)
        {
            fprintf(stderr, "L%d: division by zero\n", digit);
            free_fxn(*container);
            exit(EXIT_FAILURE);
        }
    }
    if ((*container)->n == 0)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", digit);
        free_fxn(*container);
        exit(EXIT_FAILURE);
    }

    (*container)->next->n /= (*container)->n;
    pop_fxn(container, digit);
}