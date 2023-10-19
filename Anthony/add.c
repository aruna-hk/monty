#include "monty.h"
void pop_fxn(stack_t **containter, unsigned int digit);
void free_fxn(stack_t *container);
/**
 * add_fxn - this function implement the addition of value in stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void add_fxn(stack_t **container, unsigned int digit)
{
    stack_t *my_variable;
    if ((*container) == NULL)
    {
        if ((*container)->next == NULL)
        {
            fprintf(stderr, "L%d: can't add, stack too shot\n", digit);
            free_fxn(*container);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        my_variable = (*container)->next;
        my_variable->n = my_variable->n + (*container)->n;
        pop_fxn(container, digit);
    }
}