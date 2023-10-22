#include "monty.h"

MONTYINFO mont = {-1, -1, NULL, NULL};
/**
* readfile - readfile containg opcodes
* @fd: opened file descriptor
* @STACK: pointer to top of stack
*/
void readfile()
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
		close(mont.monty_fd);
		exit(EXIT_FAILURE);
	}
	rd = read(mont.monty_fd, buffer, 1);
	while (rd == 1)
	{
		buffer[rd] = '\0';
		line = realloc(line, strlen(buffer) + strlen(line) + 1);
		strcat(line, buffer);
		if (strcmp(buffer, NEWL) == 0)
		{
			line_no++;
			if (*line == '#')
			{
				free(line);
				line = malloc(1);
				line[0] = '\0';
				continue;
			}
			printf("%s", line);
			//exec_instruction(&line, STACK, line_no, fd);
			free(line);
			line = malloc(1);
			line[0] = '\0';
		}
		rd = read(mont.monty_fd, buffer, 1);
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
	mont.monty_fd = fd;
	readfile();
	free_list(&(mont.stack));
	return (EXIT_SUCCESS);
}
