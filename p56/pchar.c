#include "monty.h"
/**
* pchar - print character of of top of stack
* @stack: pointer to to of stack
* @line_number: line number of opcode in the file
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	if ((int)(*stack)->n > 127 || (int)(*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	write(1, &((*stack)->n), sizeof(int));
	write(1, NEWL, strlen(NEWL));
}
