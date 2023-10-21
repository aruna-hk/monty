#include "monty.h"
/**
* pstr - print string --as elements from the stack
* @stack: to of stack p[ointer
* @line_number: file line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *init = *stack;

	if (*stack == NULL)
	{
		if (write(1, NEWL, strlen(NEWL)) == -1)
		{
			fprintf(stderr, "L%u: write failed\n", line_number);
			exit(EXIT_FAILURE);
		}
		return;
	}
	while (*stack != NULL)
	{
		if ((*stack)->n == 0  || (*stack)->n > 127 || (*stack)->n < 0)
		{
			if (write(1, NEWL, strlen(NEWL)) == -1)
			{
				fprintf(stderr, "L%u: write failed\n", line_number);
				exit(EXIT_FAILURE);
			}
			return;
		}
		write(1, &(*stack)->n, sizeof(int));
		*stack = (*stack)->next;
	}
	*stack = init;
}
