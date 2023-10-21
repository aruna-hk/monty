#ifndef MONTY_H
#define MONTY_H
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define DSTACK 0
#define DQUEUE 1
#define NEWL "\n"
#define USAGE "USAGE: monty file"
#define MALLOC "Error: malloc failed"
#define OPEN_ERROR "Error: Can't open file "
#define OP_NUN "unknown instruction"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *STACK;
extern char *LINE;
extern int LINE_NO;
extern char *DATA;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
* struct montyinfo - store information of monty file
* @ptr: file descriptor of opened monty file
* @data_structure: the data structure to work on queue or stack
* @line_no: line number of op code
* @line: line from the file
* @DATA: data section of opcodes that performe operation on data
* @stack: stack pointer
*/
struct montyinfo
{
	unsigned int line_no;
	int data_structure;
	FILE *file_ptr;
	char *line;
	char *opcode;
	char *DATA;
};
typedef struct montyinfo MONTYINFO;
extern MONTYINFO monty_info;

#define D_TYPE monty_info.data_structure
#define OP_C monty_info.opcode
#define LINE_NO monty_info.line_no
#define LINE monty_info.line
#define DATA monty_info.DATA
#define F_PTR monty_info.file_ptr

char *_realloc(char *existing, unsigned int extra);
void exec_instruction(stack_t **stack);
void print(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void diiv(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void free_list(stack_t **ptr);
char *__strdup(char *string);
char *filelocation(char *s_name);
int executeline(char *line, int line_no);
char *_getline(FILE *ptr);
stack_t *add_dnodeint(stack_t **head, const int n);
void (*get_instruction(char *s))(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void free_exit(stack_t **stack);
void add_stack(stack_t **ptr, stack_t **new_s);
#endif
