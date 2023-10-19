#include "monty.h"
#include <stdio.h>
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
		dprintf(STDOUT_FILENO, "%d\n", stack->n);
		stack = stack->next;
	}
}
