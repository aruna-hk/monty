#include "monty.h"

MONTYINFO monty_info = {0, 0, NULL, NULL, NULL, NULL, 0};

/**
* free_exit - free content of monty info struct
* @stack: pointer to top of stack
*/
void free_exit(stack_t **stack)
{
	fclose(F_PTR);
	if (LINE != NULL)
		free(LINE);
	if (*stack != NULL)
		free_list(stack);
}
/**
* main - open and start reading the file
* @argc: number of argumenrts
* @arglist: argument li9st
* Return: exit sucess or failure
*/
int main(int argc, char **arglist)
{
	ssize_t nread;
	size_t rread;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	F_PTR = fopen(arglist[1], "r");
	if (F_PTR == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arglist[1]);
		exit(EXIT_FAILURE);
	}
	nread = getline(&(LINE), &rread, F_PTR);
	while (nread != EOF)
	{
		LINE_NO += 1;
		OP_C = strtok(LINE, " \n");
		if ((OP_C == NULL) || (*(OP_C) == '#'))
		{
			nread = getline(&(LINE), &rread, F_PTR);
			continue;
		}
		DATA = strtok(NULL, " \n");
		if (get_instruction(OP_C) == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", LINE_NO, OP_C);
			free_exit(&stack);
			exit(EXIT_FAILURE);
		}
		get_instruction(OP_C)(&stack, LINE_NO);
		nread = getline(&(LINE), &rread, F_PTR);
	}
	free_exit(&stack);
	return (EXIT_SUCCESS);
}
