#include "monty.h"
/**
* pall - display elements of the stack
* @stack: stack pointer
* @line_number: line number of the opcode
*/
void pall(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: stack underflow\n", line_number);
		return;
	}
	while ((*stack)->next != NULL)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	fprintf(stdout, "%d\n", (*stack)->n);
	while ((*stack)->prev != NULL)
		(*stack) = (*stack)->prev;
}
