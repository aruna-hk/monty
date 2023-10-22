#include "monty.h"
/**
* rotl - rotate elements of the stack
* @stack: pointer to top of stack
* @line_number: file line number of the opcode
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, line_number);
	}
	else if ((*stack)->next->next == NULL)
		swap(stack, line_number);
	else
	{
		temp = *stack;
		tmp = (*stack)->n;

		while ((*stack)->next != NULL)
		{
			(*stack)->n = (*stack)->next->n;
			*stack = (*stack)->next;
		}
		(*stack)->n = tmp;
		*stack = temp;
	}
}
