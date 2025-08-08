#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: double pointer to head of list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next; /* start with 2nd on the list */

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
		}
	}
}
