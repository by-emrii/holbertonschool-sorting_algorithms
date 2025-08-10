#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	/* if array is null or elements is < 2, return. */
	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1) /* go thru each element except last */
	{
		min_index = i; /* assume current is smallest */

		j = i + 1;
		while (j < size) /* find index of smallest element */
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}

		/* swap only if a smaller element is found */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
		i++;
	}
}
