#include "monty.h"
/**
* pint - print to element of the stack
* @stack: pointer to top of stack
* @line_number: opcode line number in file
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_exit(stack);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
