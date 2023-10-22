#include "monty.h"
/**
* free_list - free doubly linked list --case stack
* @ptr: pointer to the list/ top of stack / queue
*/
void free_list(stack_t **ptr)
{
	if (*ptr == NULL)
		return;
	while ((*ptr)->next != NULL)
	{
		*ptr = (*ptr)->next;
		free((*ptr)->prev);
	}
	free(*ptr);
	*ptr = NULL;
}
