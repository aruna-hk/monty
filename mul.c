#include "monty.h"
/**
* mul - multiply to and secon top element store it in second and pop
*/
void mul(void)
{
	if ((STACK == NULL) || (STACK->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", LINE_NO);
		exit(EXIT_FAILURE);
	}
	STACK->next->n = (STACK->n) * (STACK->next->n);
	pop();
}
