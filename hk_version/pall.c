#include "monty.h"
/**
* pall - display elements of the stack
*/
void pall()
{
	stack_t *stack = STACK;
	if (stack == NULL)
	{
		return;
	}
	while (stack != NULL)
	{
		fprintf(stderr, "%d\n", stack->n);
		stack = stack->next;
	}
}
