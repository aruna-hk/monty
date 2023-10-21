#include "monty.h"
/**
* exec_instruction - chose the function to execute opcode in a file
*/
void exec_instruction(void)
{
	char *opcode_name;

	opcode_name = strtok(monty_info.line, " \n");
	if (opcode_name == NULL)
		return;
	monty_info.DATA = strtok(NULL, "  \n");
	if (get_instruction(opcode_name) == NULL)
	{
		fprintf(stderr, "L%d: unknown", monty_info.line_no);
		fprintf(stderr, "instruction %s\n", opcode_name);
		close(monty_info.monty_fd);
		free_list(&(monty_info.stack));
		exit(EXIT_FAILURE);
	}
	get_instruction(opcode_name)(&(monty_info.stack), monty_info.line_no);
}
