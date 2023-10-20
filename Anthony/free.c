#include "monty.h"

/**
 * free_fxn - this code free up the memory
 * @containter: this pointer to the stack
 * Return: NULL
*/
void free_fxn(stack_t *container)
{
	stack_t *repo;

	repo = container;
	while (container != NULL)
	{
		repo = container->next;
		free(container);
		container = repo;
	}
}