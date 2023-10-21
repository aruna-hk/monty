#include "monty.h"
/**
* pstr - print string --as elements from the stack
* @stack: to of stack p[ointer
* @line_number: file line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *st = *stack;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}
	while ((*stack)->next != NULL)
	{
		if ((*stack)->n == 0  || (*stack)->n > 127 || (*stack)->n < 0)
		{
			fprintf(stdout, "\n");
			return;
		}
		fprintf(stdout, "%c", (*stack)->n);
		*stack = (*stack)->next;
	}
	*stack = st;
}
