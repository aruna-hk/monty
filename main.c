#include "monty.h"
FILE *ptr;
char *DATA;
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
	char *opcode, *line, *instruction;
	int num;
	ssize_t nread;
	size_t rread;
	void (*f_ptr)(void);

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	char *file = filelocation(arglist[1]);

	ptr = fopen(file, "r");
	free(file);
	if (ptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", arglist[1]);
		return (EXIT_FAILURE);
	}
	STACK = NULL;
	LINE_NO = 1;
	nread = getline(&line,&rread, ptr);
	while (nread != -1)
	{
		line[strlen(line) - 1] = '\0';
		opcode = strtok(strdup(line), " ");
		DATA = strtok(NULL, "\0");
		get_instruction(opcode)();
		LINE_NO++;
		nread = getline(&line, &rread, ptr);
	}
	return (EXIT_SUCCESS);
}
