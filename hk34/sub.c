#include "monty.h"
/**
* sub - subtract the secon last elemnt from stack and removes to element
* @stack: pointer to top of stack
* @line_number: line number of opcode in file
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int subs;

	if (((*stack) == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_SUCCESS);
	}
	subs = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = subs;
	pop(stack, line_number);
}
