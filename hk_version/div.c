#include "monty.h"
#include <stdio.h>

void diiv()
{
	int dev;

	if (STACK == NULL || STACK->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	dev = STACK->next->n / STACK->n;
	STACK->next->n = dev;
	pop();
}	
