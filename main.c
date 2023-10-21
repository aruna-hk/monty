#include "monty.h"

MONTYINFO monty_info = {-1, 0, -1, NULL, NULL, NULL};
/**
* readfile - readfile containg opcodes
*/
void readfile(void)
{
	char *buffer, *line;
	int rd;

	line = malloc(1);
	line[0] = '\0';
	buffer = malloc(2);
	if (buffer == NULL || line == NULL)
	{
		write(2, MALLOC, strlen(MALLOC));
		write(2, NEWL, strlen(NEWL));
		close(monty_info.monty_fd);
		exit(EXIT_FAILURE);
	}
	rd = read(monty_info.monty_fd, buffer, 1);
	while (rd == 1)
	{
		buffer[rd] = '\0';
		line = realloc(line, strlen(buffer) + strlen(line) + 1);
		strcat(line, buffer);
		if (strcmp(buffer, NEWL) == 0)
		{
			monty_info.line_no += 1;
			if (*line == '#')
			{
				free(line);
				line = malloc(1);
				line[0] = '\0';
				continue;
			}
			monty_info.line = line;
			exec_instruction();
			free(line);
			line = malloc(1);
			line[0] = '\0';
		}
		rd = read(monty_info.monty_fd, buffer, 1);
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

	if (argc != 2)
	{
		write(2, USAGE, strlen(USAGE));
		write(2, NEWL, strlen(NEWL));
		return (EXIT_FAILURE);
	}
	fd = open(arglist[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, OPEN_ERROR, strlen(OPEN_ERROR));
		write(2, arglist[1], strlen(arglist[1]));
		write(2, NEWL, strlen(NEWL));
		return (EXIT_FAILURE);
	}
	monty_info.monty_fd = fd;
	readfile();
	close(monty_info.monty_fd);
	free_list(&(monty_info.stack));
	return (EXIT_SUCCESS);
}
