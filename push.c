#include "monty.h"
/**
* add_stack - push element ton the stack
* @ptr: to top of stack
* @new_s: node of stack
*/
void add_stack(stack_t **ptr, stack_t **new_s)
{
	(*new_s)->prev = NULL;
	if (*ptr == NULL)
	{
		(*new_s)->next = NULL;
		*ptr = *new_s;
	}
	else
	{
		(*ptr)->prev = *new_s;
		(*new_s)->next = *ptr;
		*ptr = *new_s;
	}
}
/**
* push - push opcode add to the stack
* @stack: pointer to of data structure structure  --stack/ queue
* @line_no: line number of opcode in file
*/
void push(stack_t **stack, unsigned int line_no)
{
	stack_t *new;
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
	new = malloc(sizeof(stack_t));
	new->n = data;
	if (new == NULL)
	{
		free_exit(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add_stack(stack, &new);
}
