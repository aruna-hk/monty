#include "monty.h"
/**
* filelocation - get full file path
* @s_name: short hand name
* Return: full file path
*/
char *filelocation(char *s_name)
{
	char *tok;
	int len;
	char *s_name_dup;
	char *file_dir;

	if (*s_name == '/')
		return (_strdup(s_name));
	s_name_dup = _strdup(s_name);
	strcpy(s_name_dup, s_name);
	tok = strtok(s_name_dup, "/");
	file_dir = _strdup(getenv("PWD"));
	while (strcmp(tok, ".") == 0 || strcmp(tok, "..") == 0)
	{
		if (strcmp(tok, "..") == 0)
		{
			len = strlen(file_dir) - 1;
			while (file_dir[len] != '/')
			{
				file_dir[len] = '\0';
				len--;
			}
			file_dir[len] = '\0';
		}
		tok = strtok(NULL, "/");
	}
	file_dir = realloc(file_dir, strlen(file_dir) + strlen(tok) + 2);
	strcat(file_dir, "/");
	strcat(file_dir, tok);
	free(s_name_dup);
	return (file_dir);
}
