#include "monty.h"
char *strdup(char *string)
{
	char *dup = malloc(strlen(string) + 1);

	dup[0] = '\0';
	strcpy(dup, string);
	return (dup);
}
