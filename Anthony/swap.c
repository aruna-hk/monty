#include "monty.h"

/**
 * add_fxn - this function implement the swapping of value in stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void swap_fxn(stack_t **container, unsigned int digit)
{
    stack_t *orign, *replace;
    if ((*container) == NULL)
    {
        if ((*container)->next == NULL)
        {
            fprintf(stderr, "L%d: can't swap, stack too shot\n", digit);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        orign = *container;
        replace = orign->next;

        orign->next = replace->next;
        replace->next = orign->prev;

        orign->prev = replace;
        replace->next = orign;

        (*container) = replace;
    }

}
