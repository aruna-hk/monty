#include "monty.h"
/**
* _realloc - _reallocate space
* @existing: existing memory and its content
* @new_size: new space
* Return: pointer to new space
*/
char *_realloc(char *existing, unsigned int new_size)
{
	char *new;

	if (new_size == 0 && existing != NULL)
		return (NULL);
	if (existing == NULL && new_size != 0)
		return (malloc(new_size));
	new = malloc(new_size);
	new[0] = '\0';
	strcpy(new, existing);
	return (new);
}
