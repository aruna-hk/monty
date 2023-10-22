#include "monty.h"
/**
* pstr - print string --as elements from the stack
* @s: to of stack pointer
* @line_number: file line number
*/
void pstr(stack_t **s, unsigned int line_number)
{
	stack_t *st = *s;
	int nn;
	(void) line_number;

	if (*s == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}
	C_FLAG = 1;
	nn = (*s)->n;
	while ((*s)->next != NULL && nn != 0 && (nn < 127 || (nn < 0)))
	{
		pchar(s, line_number);
		nn = (*s)->n;
		*s = (*s)->next;
	}
	*s = st;
	fprintf(stdout, "\n");
}
