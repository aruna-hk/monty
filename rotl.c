#include "monty.h"
/**
* rotl - rotate elements of the stack
* @stack: pointer to top of stack
* @line_number: file line number of the opcode
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, line_number);
	}
	else if ((*stack)->next->next == NULL)
		swap(stack, line_number);
	else
	{
		tmp = *stack;

		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = tmp;
		tmp->prev = *stack;
		tmp = tmp->next;
		(*stack)->next->next = NULL;
		tmp->prev = NULL;
		*stack = tmp;
	}
}
