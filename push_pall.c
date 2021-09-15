#include "monty.h"
size_t list_len(const stack_t *stack)
{
	int count;
	if (stack == NULL)
		return (0);
	for (count = 0; stack != NULL; count++)
		{
			stack = stack->next;
		}
	return (count);
}


/**
 * push - pushes a value to a stack_t linked list
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		malloc_error();


	new_node->n = number;
	new_node->prev = NULL;
	if (*stack == NULL)  /* validate if empty stack */
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else /* if is not empty stack */
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}


/**
* pall - prints the values of a stack_t linked list
* @stack: pointer to the top mode node of a stack_t linked list
* @line_number: current working line number
*/

void pall(stack_t **stack, unsigned int line_number)
     {
/*		size_t len;*/
		stack_t *tmp = (*stack);

/*		len = list_len(*stack);
		printf("number of nodes: %ld\n", len);*/
		while (tmp)
			{
				printf("%d\n", tmp->n);
				tmp = tmp->next;
			}
			(void)line_number;
     }
