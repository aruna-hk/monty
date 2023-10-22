#include "monty.h"
/**
* rotr - rotate linked list backwards
* @stack: pointer to stack
* @line_number: line number of opcode
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		nop(stack, line_number);
	}
	else
	{
		tmp = *stack;
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = tmp;
		tmp->prev = *stack;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
