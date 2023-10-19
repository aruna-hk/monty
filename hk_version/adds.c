#include "monty.h"
/**
* add - add top two of the stack
*/
void add(void)
{
	int adition;

	if ((STACK == NULL) || (STACK->next == NULL))
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	adition = STACK->n + STACK->next->n;
	STACK->next->n = adition;
	pop();
}
