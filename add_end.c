#include "monty.h"
/**
* add_end - add node at the end of the list
* @head: pointer to head of the list
* @n: value to insert
*/
void add_end(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

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
		*head = new;
	else
	{
		while ((*head)->next != NULL)
			(*head) = (*head)->next;
		(*head)->next = new;
		new->prev = *head;
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;
	}
}
