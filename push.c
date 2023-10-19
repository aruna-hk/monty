#include "monty.h"
/**
* push - adde node at the beggining of doubly linked list
* @stack: pointer to top of stack
* @line_number: line number of the opcode
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		line_number = EXIT_FAILURE;
		fprintf(stderr, "Error: malloc failed\n");
		exit(line_number);
	}
	new->n = atoi(DATA);
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	else
	{
		(*stack)->prev = new;
		new->next = (*stack);
		(*stack) = new;
		return;
	}
}
