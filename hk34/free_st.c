#include "monty.h"
/**
* free_list - free doubly linked list --case stack
* @ptr: pointer to the list/ top of stack / queue
*/
void free_list(stack_t **ptr)
{
	while ((*ptr) != NULL)
	{
		free((*ptr)->prev);
		*ptr = (*ptr)->next;
	}
}
