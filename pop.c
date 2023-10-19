#include "monty.h"
/**
* pop - remove top element of the stack
*/
void pop(void)
{
	if (STACK == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	if (STACK->next == NULL)
	{
		free(STACK);
		STACK = NULL;
	}
	else
	{
		STACK = STACK->next;
		free(STACK->prev);
		STACK->prev = NULL;
	}
}
