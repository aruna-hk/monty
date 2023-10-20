#include "monty.h"
/**
* nop - does nothing
* @stack: pointer to top of stack
* @line_number: line number of the opcode
*/
void nop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		exit(EXIT_FAILURE);
	exit(line_number);
}
