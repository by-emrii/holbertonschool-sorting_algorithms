#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap_ints - swaps two int in an array
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

/**
 * lomuto_partition - partitions the array using lomuto
 * @array: array to partition
 * @low: starting index
 * @high: ending index - pivot
 * @size: size of the array
 * Return: the final pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /* last element */
	int i = low - 1; /* for swapping smaller elements */
	int j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
		j++;
	}

	if (i + 1 != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursion - recursive helper for quick sort func
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of array
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: the array of int to be sorted
 * @size: size of the array
 * implement the Lomuto partition scheme
 * pivot should always be the last element of the partition being sorted.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursion(array, 0, (int)size - 1, size);
}
