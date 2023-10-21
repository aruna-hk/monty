#include "monty.h"
/**
* diiv - devide second last element of stacck and remove first
* @stack: pointer to top of the stack
* @line_number: line number of tyhe file
*/
void diiv(stack_t **stack, unsigned int line_number)
{
	int dev;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	dev = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = dev;
	pop(stack, line_number);
}
