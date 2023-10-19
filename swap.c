#include "monty.h"
/**
* swap - swap to element of the stack with second top
*/
void swap(void)
{
	int temp;

	if ((STACK == NULL) || (STACK->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short", LINE_NO);
		exit(EXIT_FAILURE);
	}
	temp = STACK->n;
	STACK->n = STACK->next->n;
	STACK->next->n = temp;
}
