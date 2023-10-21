#ifndef MONTY_H
#define MONTY_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void push_component(stack_t **container, int digit, unsigned int debuger);
void pop_fxn(stack_t **containter, unsigned int digit);
void free_fxn(stack_t *container);
int strcmp(char* str1, char* str2);
extern stack_t *stack = NULL;
void nop_code(stack_t **container, unsigned int digit);
void mul_fxn(stack_t **container, unsigned int digit);
void div_fxn(stack_t **container, unsigned int digit);
void add_fxn(stack_t **container, unsigned int digit);
void sub_fxn(stack_t **container, unsigned int digit);
void swap_fxn(stack_t **container, unsigned int digit);    void pint_point(stack_t **container, unsigned int digit);
void pall_print(stack_t ** containter, __attribute__((unuse
d))unsigned int digit);
#endif