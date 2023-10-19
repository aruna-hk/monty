#include "monty.h"
/**
* mul - multiply to and secon top element store it in second and pop
* @stack: pointer to top of stack
* @line_number: line number of opcode
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->n) * ((*stack)->next->n);
	pop(stack, line_number);
}
