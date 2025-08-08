#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: ptr to the array of int to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped = 1; /* set to true to enter loop */
	int temp;

	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1) /* so i does not go out of valid range*/
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = 1; /* swap has happened */
			}
			i++;
		}
		if (swapped == 0)
			break;
		/* loop will keep going as swapped = true until false; reset i */
	}
}
