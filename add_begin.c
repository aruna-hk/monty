#include "monty.h"
/**
* add_begin - adde node at the beggining of doubly linked list
* @head: head of the list
* @n: value to insert
*/
void add_begin(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_exit(head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = (*head);
		*head = new;
	}
}
