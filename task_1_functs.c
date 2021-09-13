#include "monty.h"
/**
 *
 *
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if ((data_n == '\0') ||((data_n < 48) || (data_n > 57)))
		no_int_error(line_number);
	new_node->n = data_n;
	new_node->next = (*head);
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
	return (new_node);
}

/**
 *
 *
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int count;

	if (stack == NULL)
		return (0);
	for (count = 0; stack != NULL; count++)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
	return (count);
}
