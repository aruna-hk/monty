#include "monty.h"
/**
* swap - swap to element of the stack with second top
* @stack: pointer to top of the stack
* @line_number: line number of the opcode
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_exit(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
