#include "monty.h"
/**
* pall - display elements of the stack
* @stack: stack pointer
* @line_number: line number of the opcode
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *init = *stack;

	(void) line_number;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	*stack = init;
}
