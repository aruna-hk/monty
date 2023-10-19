#include "monty.h"
#include <stdio.h>

void pint()
{
	if (STACK == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", STACK->n);
}
