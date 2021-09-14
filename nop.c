#include "monty.h"

/**
 * nop - does nothing
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */


void  nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
