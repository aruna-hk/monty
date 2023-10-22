#include "monty.h"
char *DATA;
/**
* main - open and start reading the file
* @argc: number of argumenrts
* @arglist: argument li9st
* Return: exit sucess or failure
*/
int main(int argc, char **arglist)
{
	char *line, *file, *opcode;
	FILE *ptr;
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int LINE_NO = 1;
	stack_t *STACK = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}
	file = filelocation(arglist[1]);
	ptr = fopen(file, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arglist[1]);
		free(file);
		return(EXIT_FAILURE);
	}
	free(file);
	line = _getline(ptr);
	while (line != NULL)
	{
		while (*line == ' ')
			line++;
		if(*line == '\n')
		{
			line = _getline(ptr);
			continue;
		}
		opcode = strtok(_strdup(line), " \n");
		DATA = strtok(NULL, "\0");
		f = get_instruction(opcode);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", LINE_NO, opcode);
			exit(EXIT_FAILURE);
		}
		f(&STACK, LINE_NO);
		LINE_NO++;
		line = _getline(ptr);
	}
	free(line);
	return(EXIT_SUCCESS);
}
