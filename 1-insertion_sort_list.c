#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		prev = curr->prev;
		while (prev && prev->n > curr->n)
		{
			prev->next = curr->next;
			if (curr->next)
				curr->next->prev = prev;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;
			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;
			prev = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
