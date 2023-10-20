#include "monty.h"
void free_fxn(stack_t *container);
/**
 * nop_code - this function do nothing
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void nop_code(stack_t **container, unsigned int digit)
{
	 (void) container;
    (void) digit;
    free_fxn(*container);
}