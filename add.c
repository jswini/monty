#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		add_error(line_number);

	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
}
