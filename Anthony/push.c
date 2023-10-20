#include "monty.h"
void free_fxn(stack_t *container);
/**
 * isEmpty - this function check whether the stack is empty
 * @stack: my stack
 * Return: null
*/
int isEmpty(stack_t **stack) 
{
    return (*stack)->n = -1;
}
/**
 * push_fxn - this function implement add element to the stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void push_fxn(stack_t **container, unsigned int digit)
{
    stack_t *my_new_node = (stack_t *)malloc(sizeof(stack_t));
    if (my_new_node == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", digit);
        free_fxn(*container);
        exit(EXIT_FAILURE);
    }
    my_new_node->n = digit;
    my_new_node->prev = NULL;

    if(isEmpty(container))
    {
        my_new_node->next = NULL;
    }
    else
    {
        my_new_node->next = *container;
        (*container)->prev = my_new_node;
    }
    (*container) = my_new_node;
}