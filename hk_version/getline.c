#include "monty.h"

char *getline(FILE *ptr)
{
	char *line;
	char *buffer;
	size_t nread;


	buffer = malloc(2);
	line = malloc(1);
	line[0] = '\0';
	while(1)
	{
		nread = fread(buffer, sizeof(char), 1, ptr);
		if (nread != 1)
			return (NULL);
		buffer[nread] = '\0';
		if (strcmp(buffer, "\n") == 0)
		{
			line = realloc(line, strlen(line) + strlen("\n") + 1);
			strcat(line, "\n");
			return (line);
		}
		line = realloc(line, strlen(line) + strlen(buffer) + 2);
		strcat(line, buffer);
	}
	return (NULL);
}
