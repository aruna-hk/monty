#include "monty.h"
/**
* pstr - print string --as elements from the stack
* @s: to of stack pointer
* @line_number: file line number
*/
void pstr(stack_t **s, unsigned int line_number)
{
	stack_t *st = *s;

	if (*s == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}
	C_FLAG = 1;
	while (*s != NULL)
	{
		if ((*s)->n > 127 || (*s)->n < 0 || (*s)->n == 0)
			break;
		pchar(s, line_number);
		*s = (*s)->next;
	}
	*s = st;
	fprintf(stdout, "\n");
	C_FLAG = 0;
}
