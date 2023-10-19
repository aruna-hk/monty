#include "monty.h"
void free_fxn(stack_t *container);
/**
 * pop_fxn - this function delete an element in the at the top of the stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void pop_fxn(stack_t **container, unsigned int digit)
{
    stack_t *my_teporary_ptr;
    if ((*container) == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", digit);
        free_fxn(*container);
        exit(EXIT_FAILURE);
    }
    if (!((*container)->next))
    {
        (*container)->next->prev = NULL;
    }

    my_teporary_ptr = *container;
    *container = (*container)->next;
    free(my_teporary_ptr);
}