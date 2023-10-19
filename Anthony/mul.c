#include "monty.h"

void pop_fxn(stack_t **containter, unsigned int digit);
void free_fxn(stack_t *container);
/**
 * mul_fxn - this function implement the multiplication of value in stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void mul_fxn(stack_t **container, unsigned int digit)
{
    stack_t *variable;
    if ((*container) == NULL)
    {
        if ((*container)->next == NULL)
        {
            fprintf(stderr, "L%d: can't mul, stack too shot\n", digit);
            free_fxn(*container);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        variable = (*container)->next;
        variable->n = variable->n * (*container)->n;
        pop_fxn(container, digit);
    }
}