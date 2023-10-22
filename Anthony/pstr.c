#include "monty.h"
/**
 * print_str_ascending - this prototype print the string starting from the top
 * @containter: stack
 * @digit: debuger
 * Return: null
*/
void print_str_ascending(stack_t **container, __attribute__((unused)) unsigned int digit)
{
    stack_t *present_state = *container;
    
    while (present_state != NULL && (present_state->n > 0 && present_state->n <= 127))
    {
        if (present_state->n != 0)
        {
            putchar(present_state->n);
        }
        else
        {
            present_state = present_state->next;
        }
    }
    putchar('\n');
}
