#include "monty.h"
/**
 * strcmp - this function implement the addition of value in stack
 * @str1: string one
 * @str2: string two
 * Return: nothing 
*/
int strcmp(const char *str1, const char *str2) 
{
    while (*str1 && *str2) 
    {
        if (*str1 != *str2) 
	{
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == *str2);
}
