#include "monty.h"
/**
* __strdup - string duplication function
* @string: string to duplicate
* Return: duplicated string
*/
char *__strdup(char *string)
{
	char *dup = malloc(strlen(string) + 1);

	dup[0] = '\0';
	strcpy(dup, string);
	return (dup);
}
