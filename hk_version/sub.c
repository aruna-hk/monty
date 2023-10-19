#include "monty.h"
#include <stdio.h>
void sub()
{
	int subs;

	if (STACK == NULL || STACK->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", LINE_NO);
		exit(EXIT_SUCCESS);
	}
	subs = STACK->next->n - STACK->n;
	STACK->next->n = subs;
	pop();
}
