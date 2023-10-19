#include "monty.h"
#include <stdio.h>

void pint()
{
	if (STACK == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty", LINE_NO);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", STACK->n);
}
