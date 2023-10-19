#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
extern FILE *ptr;
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
extern char  *DATA;
extern char *LINE;
extern int LINE_NO;
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
	void (*get_instruction)(void);
} instruction_t;

void print();
void push();
void pall();
void pint();
void pop();
void add();
void swap();
void sub();
void diiv();
char *strdup(char *string);
char *filelocation(char *s_name);
int executeline(char *line, int line_no);
char *getline(FILE *ptr);
stack_t *add_dnodeint(stack_t **head, const int n);
void (*get_instruction(char *s))(void);
