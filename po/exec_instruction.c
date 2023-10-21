#include "monty.h"
/**
* exec_instruction - chose the function to execute opcode in a file
* @line: pointer of line read from the file
* @STACK: pointer to the top of stack
* @line_number: pline number
*/
void exec_instruction()
{
	char *opcode_name;

	while (*monty_info.line == ' ')
		monty_info.line += 1;
	opcode_name = strtok(monty_info.line, " \n");
	if (opcode_name == NULL)
		return;
	monty_info.DATA = strtok(NULL, "  \n");
	if (get_instruction(opcode_name) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", monty_info.line_no, opcode_name);
		close(monty_info.monty_fd);
		free_list(&(monty_info.stack));
		exit(EXIT_FAILURE);
	}
	get_instruction(opcode_name)(&(monty_info.stack), monty_info.line_no);
}
