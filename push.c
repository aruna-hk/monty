#include "monty.h"
/**
* add_stack - push element ton the stack
* @ptr: to top of stack
* @new: node of stack
*/
void add_stack(stack_t **ptr, stack_t **new)
{
	(*new)->prev = NULL;
	if (*ptr == NULL)
	{
		(*new)->next = NULL;
		*ptr = *new;
	}
	else
	{
		(*ptr)->prev = *new;
		(*new)->next = *ptr;
		*ptr = *new;
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
	char *sdata = monty_info.DATA;
	int data;

	if (monty_info.DATA == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_no);
		free_list(&(monty_info.stack));
		free(monty_info.line);
		close(monty_info.monty_fd);
		exit(EXIT_FAILURE);
	}
	if (*monty_info.DATA == '-')
		monty_info.DATA += 1;
	while (*(monty_info.DATA) != '\0')
	{
		if ((int) *(monty_info.DATA) > 57 || (int) *(monty_info.DATA) < 48)
		{
			free(monty_info.line);
			free_list(stack);
			close(monty_info.monty_fd);
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		monty_info.DATA += 1;
	}
	monty_info.DATA = sdata;
	data = atoi(monty_info.DATA);
	new = malloc(sizeof(stack_t));
	new->n = data;
	if (new == NULL)
	{
		free(monty_info.line);
		free_list(stack);
		close(monty_info.monty_fd);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add_stack(stack, &new);
}
