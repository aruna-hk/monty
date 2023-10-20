#include "monty.h"
char *DATA;
/**
* exec_instruction - chose the function to execute opcode in a file
* @line: pointer of line read from the file
* @STACK: pointer to the top of stack
* @line_number: pline number
*/
void exec_instruction(char **line, stack_t **STACK, unsigned int line_number)
{
	char *opcode_name;
	opcode_name = strtok(*line, " \n");
	if (opcode_name == NULL)
		return;
	DATA = strtok(NULL, NEWL);
	if (get_instruction(opcode_name) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_name);
		free(*line);
		exit(EXIT_FAILURE);
	}
	get_instruction(opcode_name)(STACK, line_number);
}
