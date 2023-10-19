#include "monty.h"
/**
* push - adde node at the beggining of doubly linked list
*/
void push()
{
	char *data;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_SUCCESS);
	}
	data = DATA;
	while (*data != '\0')
	{	
		if (*data > 57 && *data < 48)
		{
			fprintf(stderr, "Line: usage: push integer\n");
			exit(EXIT_FAILURE);
		}
		data++;
	}
	new->n = atoi(DATA);
	new->prev = NULL;
	new->next = NULL;
	if (STACK == NULL)
	{
		STACK = new;
		return;
	}
	else
	{
		STACK->prev = new;
		new->next = STACK;
		STACK = new;
		return;
	}
}
