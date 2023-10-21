#include "monty.h"
/**
* swap - swap to element of the stack with second top
* @stack: pointer to top of the stack
* @line_number: line number of the opcode
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
