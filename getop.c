#include "monty.h"
/**
* get_op_func -- find and return pointer to
* respective function to allow arithmetic operation--
* @s: sign string
* Return: pointer to operators function/NULL
*/
void (*get_instruction(char *s))(void)
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
		{NULL, NULL},
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			return (ops[i].get_instruction);
		}
		i++;
	}
	return (NULL);
}
