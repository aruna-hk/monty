#include "monty.h"
#include <stdlib.h>
char *DATA;
FILE *ptr;
stack_t *STACK;
int LINE_NO;
/**
* main - open and start reading the file
* @argc: number of argumenrts
* @arglist: argument li9st
* Return: exit sucess or failure
*/
int main(int argc, char **arglist)
{
	char *line, *file, *opcode;
	void (*f)();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = filelocation(arglist[1]);

	ptr = fopen(file, "r");
	free(file);
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arglist[1]);
		return (EXIT_FAILURE);
	}
	STACK = NULL;
	LINE_NO = 1;
	line = getline(ptr);
	while (line != NULL)
	{
		line[strlen(line) - 1] = '\0';
		while (*line == ' ')
			line++;
		if(*line == '\0')
		{
			line = getline(ptr);
			continue;
		}
		opcode = strtok(strdup(line), " \n");
		DATA = strtok(NULL, "\0");
		f = get_instruction(opcode);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", LINE_NO, opcode);
			return (EXIT_FAILURE);
		}
		f();
		LINE_NO++;
		line = getline(ptr);
	}
	return (EXIT_SUCCESS);
}
