#include "monty.h"
/**
* get_instruction -- find and return pointer to
* respective function to allow arithmetic operation--
* @s: instruction pointer
* Return: pointer to operators function/NULL
*/
void (*get_instruction(char *s))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", diiv},
		{"mod", mod},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL},
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
