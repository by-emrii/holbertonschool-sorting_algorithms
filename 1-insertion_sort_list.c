#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in asc order
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

	/* outer loop goes thru each node 1 by 1*/
	while (current != NULL)
	{
		temp = current->next; /* store next node to move to after */

		/* inner loop: move current node backwards while smaller than prev */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* disconnect current from prev node*/
			current->prev->next = current->next;

			/* if current not at end, connect node after current to current->prev */
			if (current->next != NULL)
				current->next->prev = current->prev;

			/* swap current with its previous node */
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			/* if current is now at head, update list head */
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;

			/* print list after each swap */
			print_list(*list);
		}
		/* move to the next saved node, keep sorting */
		current = temp;
	}
}
