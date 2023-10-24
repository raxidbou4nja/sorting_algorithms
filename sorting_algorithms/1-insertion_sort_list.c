#include "sort.h"

/**
 * insertion_sort_list - it sorts a doubly linked list in ascending
 * order using the Insertion Sort algorithm.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
			prev = temp->prev;
		}

		current = current->next;
	}
}
