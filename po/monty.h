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
* @monty_fd: file descriptor of opened monty file
* @data_structure: the data structure to work on queue or stack
* @DATA: data section of opcodes that performe operation on data
*/
struct montyinfo
{
	int monty_fd;
	int line_no;
	int data_structure;
	char *line;
	char *DATA;
	stack_t *stack;
};
typedef struct montyinfo MONTYINFO;

extern MONTYINFO monty_info;

char *_realloc(char *existing, unsigned int extra);

void exec_instruction();

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
void rotl(stack_t **stack, unsigned int line_number);
void free_list(stack_t **ptr);
char *__strdup(char *string);
char *filelocation(char *s_name);
int executeline(char *line, int line_no);
char *_getline(FILE *ptr);
stack_t *add_dnodeint(stack_t **head, const int n);
void (*get_instruction(char *s))(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
#endif
