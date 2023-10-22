#include "monty.h"
int strcmp(const char* str1, const char* str2);
void nop_code(stack_t **container, unsigned int digit);
void mul_fxn(stack_t **container, unsigned int digit);
void div_fxn(stack_t **container, unsigned int digit);
void add_fxn(stack_t **container, unsigned int digit);
void sub_fxn(stack_t **container, unsigned int digit);
void swap_fxn(stack_t **container, unsigned int digit);
void pint_point(stack_t **container, unsigned int digit);
void pall_print(stack_t **containter, __attribute__((unused))unsigned int digit);
void push_fxn(stack_t **container, unsigned int digit);
/**
 * exec_fxn - this function implement the prototye
 * @container: array of pointer
 * @digit: my debuger
 * Return: nothing 
*/
void exec_fxn(char *opcode, char *my_argument, unsigned int digit, stack_t **stack)
{
    digit = 0;
    val = atoi(my_argument);
    
    if (opcode[0] == '#')
    {
        return;
    }
    if (strcmp(opcode, "push") == 0)
    {
        push_fxn(stack, digit);
    }
    else
    {
        switch (opcode[0])
        {
            case 'p':
                if (strcmp(opcode, "pall") == 0)
                {
                    pall_print(stack, val);
                }
                else if (strcmp(opcode, "pint") == 0) 
                {
                    pint_point(stack, val);
                }
                break;
            case 's':
                if (strcmp(opcode, "swap") == 0)
                {
                    swap_fxn(stack, val);
                }
                else if (strcmp(opcode, "sub"))
                {
                    sub_fxn(stack, val);
                }
                break;
            case 'a':
                if (strcmp(opcode, "add") == 0)
                {
                    add_fxn(stack, val);
                }
                break;
            case 'd':
                if (strcmp(opcode, "div") == 0)
                {
                    div_fxn(stack, val);
                }
                break;
            case 'm':
                if (strcmp(opcode, "mul"))
                {
                    mul_fxn(stack, val);
                }
                break;
            case 'n':
                if (strcmp(opcode, "nop"))
                {
                    nop_code(stack, val);
                }
                break; 
            default:
                fprintf(stderr, "L%d: unknown instruction %s\n", digit, opcode);
                exit(EXIT_FAILURE);
                break;
        }
    }

}
