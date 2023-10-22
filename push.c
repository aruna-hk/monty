#include "monty.h"
/**
* push - push opcode add to the stack
* @stack: pointer to of data structure structure  --stack/ queue
* @line_no: line number of opcode in file
*/
void push(stack_t **stack, unsigned int line_no)
{
	char *sdata = DATA;
	int data;

	if (DATA == NULL)
	{
		free_exit(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (*DATA == '-')
		DATA += 1;
	while (*(DATA) != '\0')
	{
		if ((int) *(DATA) > 57 || (int) *(DATA) < 48)
		{
			free_exit(stack);
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		DATA += 1;
	}
	DATA = sdata;
	data = atoi(DATA);
	if (D_TYPE == DQUEUE)
		add_end(stack, data);
	else if (D_TYPE == DSTACK)
		add_begin(stack, data);
}
