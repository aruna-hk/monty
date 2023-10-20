#include "monty.h"
/**
* readfile - readfile containg opcodes
* @fd: opened file descriptor
* @STACK: pointer to top of stack
*/
void readfile(int fd, stack_t **STACK)
{
	char *buffer, *line;
	int rd, line_no = 0;

	line = malloc(1);
	line[0] = '\0';
	buffer = malloc(2);
	if (buffer == NULL || line == NULL)
	{
		write(2, MALLOC, strlen(MALLOC));
		write(2, NEWL, strlen(NEWL));
		exit(EXIT_FAILURE);
	}
	rd = read(fd, buffer, 1);
	while (rd == 1)
	{
		buffer[rd] = '\0';
		line = _realloc(line, strlen(buffer) + strlen(line) + 1);
		strcat(line, buffer);
		if (strcmp(buffer, NEWL) == 0)
		{
			line_no++;
			if (*line == '#')
			{
				line[0] = '\0';
				line = _realloc(line, 1);
				continue;
			}
			exec_instruction(&line, STACK, line_no);
			line[0] = '\0';
			line = _realloc(line, 1);
		}
		rd = read(fd, buffer, 1);
	}
	free(buffer);
	free(line);
}

/**
* main - open and start reading the file
* @argc: number of argumenrts
* @arglist: argument li9st
* Return: exit sucess or failure
*/
int main(int argc, char **arglist)
{
	int fd;
	stack_t *STACK = NULL;
	char *file;

	if (argc != 2)
	{
		write(2, USAGE, strlen(USAGE));
		write(2, NEWL, strlen(NEWL));
		return (EXIT_FAILURE);
	}
	file = filelocation(arglist[1]);
	fd = open(file, O_RDONLY);
	free(file);
	if (fd == -1)
	{
		write(2, OPEN_ERROR, strlen(OPEN_ERROR));
		write(2, arglist[1], strlen(arglist[1]));
		write(2, NEWL, strlen(NEWL));
		return (EXIT_FAILURE);
	}
	readfile(fd, &STACK);
	return (EXIT_SUCCESS);
}
