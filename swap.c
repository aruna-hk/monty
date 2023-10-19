#include "monty.h"
#include <stdio.h>
void swap()
{
	int temp;

	if (STACK == NULL || STACK->next == NULL)
	{
		dprintf(STDERR_FILENO, "L<line_number>: can't swap, stack too short");
		exit(EXIT_FAILURE);
	}
	temp = STACK->n;
	STACK->n = STACK->next->n;
	STACK->next->n = temp;
}
