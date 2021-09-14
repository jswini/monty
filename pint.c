#include "monty.h"

/**
 * pint- prints the value at the top of the stack, followed by a new line
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp != NULL)
		printf("%d\n", tmp->n);

	else
		no_int_error(line_number);
}
