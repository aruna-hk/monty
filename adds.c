#include "monty.h"
/**
* add - add top two of the stack
* @stack: pointer to the stack
* @line_number: line number in the file
*/
void add(stack_t **stack, unsigned int line_number)
{
	int adition;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stdout, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	adition = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = adition;
	pop(stack, line_number);
}
