#include "sort.h"

/**
 * insertion_sort_list - sorts using insertion format
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *next, *current;
	int i = 0;

	current = *list;
	printf("%d, %d\n", i, current->n);
	next = current->next;
	printf("%d, %d\n", i, next->n);
	while (next->next != NULL)
	{
		while (current->n > next->n)
		{
			tmp->n = current->n;
			current->n = next->n;
			next->n = tmp->n;
			next = next->next;
			i++;
		}
		current = current->next;
		print_list(*list);
		free(tmp);
	}
	free(next);
	free(current);
}
