#include "monty.h"
void pop_fxn(stack_t **containter, unsigned int digit);
void free_fxn(stack_t *container);
/**
 * add_fxn - this function implement the subtraction of value in stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void sub_fxn(stack_t **container, unsigned int digit)
{
    stack_t *variable;
    if ((*container) == NULL)
    {
        if ((*container)->next == NULL)
        {
            fprintf(stderr, "L%d: can't sub, stack too shot\n", digit);
            free_fxn(*container);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        variable = (*container)->next;
        variable->n = variable->n - (*container)->n;
        pop_fxn(container, digit);
    }
}