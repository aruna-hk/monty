#include "monty.h"
/**
* add_begin - adde node at the beggining of stack
* @head: head of the list
* @n: value to insert
* Return: new node
*/
stack_t *add_begin(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(head);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	(*head)->prev = new;
	new->next = (*head);
	*head = new;
	return (new);
}
