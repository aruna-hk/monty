#include "monty.h"
/**
* ret_numb - return number from string works on exter varibale DATA
* @line_number: line number in the file
* Return: interger
*/
int ret_numb(unsigned int line_number)
{
	char *num = __strdup(DATA);

	while (*num == ' ')
		num++;
	if (*num == '\n' || *num == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_SUCCESS);
	}
	else if (*num == '-')
	{
		num++;
		while (*num != '\0' && *num != ' ')
		{
		if ((int)*num > 57 || (int)*num < 48)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
		}
		num++;
		}
		return ((atoi(DATA)));
	}
	else
	{
		while (*num != '\0' && *num != ' ')
		{
		if ((int)*num > 57 || (int)*num < 48)
		{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		}
		num++;
		}
	}
	return (atoi(DATA));
}
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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = ret_numb(line_number);
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
