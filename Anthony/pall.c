#include "monty.h"
/**
 * pall_print - this function display element in the stack
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void pall_print(stack_t ** containter, __attribute__((unused))unsigned int digit)
{
    stack_t *node = *containter;
    for (; node != NULL;)
    {
        printf("%d\n", node->n);
        node = node->next;
    }
}