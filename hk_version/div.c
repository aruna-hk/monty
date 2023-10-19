#include "monty.h"
/**
* diiv - devide second last element of stacck and remove first
*/
void diiv(void)
{
	int dev;

	if ((STACK == NULL) || (STACK->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	dev = STACK->next->n / STACK->n;
	STACK->next->n = dev;
	pop();
}
