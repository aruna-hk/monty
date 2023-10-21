#include "monty.h"
/**
* mod - perform modulus of element in stack
* @stack:stack pointer
* @line_number: line number of the opcode
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);
}
