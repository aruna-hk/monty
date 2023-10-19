#include "monty.h"
/**
* sub - subtract the secon last elemnt from stack and removes to element
*/
void sub(void)
{
	int subs;

	if ((STACK == NULL) || (STACK->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", LINE_NO);
		exit(EXIT_SUCCESS);
	}
	subs = STACK->next->n - STACK->n;
	STACK->next->n = subs;
	pop();
}
