#include "monty.h"
/**
* queue - set queue data struct
* @stack: pointer to tp of stack
* @line_number: opcode line number
*/
void queue(stack_t **stack, unsigned int line_number)
{
	nop(stack, line_number);

	D_TYPE = QUEUE;
}
