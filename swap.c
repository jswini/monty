#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */


void swap(stack_t **stack, unsigned int line_number)
{
	int num;
	if (*stack == NULL || (*stack)->next == NULL)
		swap_error(line_number);


	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
