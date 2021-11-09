#include "sort.h"

/**
 * bubble_sort - sorts using bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	int tmp;
	int swapped = 0;

	if (size <= 2)
	{
		return;
	}
	while (swapped == 0)
	{
		swapped = 1;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
				swapped = 0;
			}
		}
	}
}
