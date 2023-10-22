#include "monty.h"
/**
* add_end - add node at the end queue
* @head: pointer to head of the list
* @n: value to insert
* Return: added node
*/
stack_t *add_end(stack_t **head, const int n)
{
	stack_t *tmp;
	stack_t *new = malloc(sizeof(stack_t));

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
		return (*head);
	}
	tmp = *head;
	while ((*head)->next != NULL)
		(*head) = (*head)->next;
	(*head)->next = new;
	new->prev = *head;
	*head = tmp;
	return (*head);
}
