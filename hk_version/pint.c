#include "monty.h"
/**
* pint - print to element of the stack
*/
void pint()
{
	if (STACK == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", STACK->n);
}
