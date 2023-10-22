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
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
