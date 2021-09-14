#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack == NULL)
		perror(line_number);

	tmp = tmp->next;
	free(*stack);
	*stack = tmp;
}
