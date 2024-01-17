#include "sort.h"

/**
 * insertion_sort_list - insertion to sort a doubly linked list
 *
 * @list: the address of the node 
 *
 * Return: nothing (void)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y, *a;

	if (!list || !*list || !(*list)->next)
		return;
	x = (*list)->next;
	while (x != NULL)
	{
		y = x;
		x = x->next;
		while (y != NULL && y->prev != NULL)
		{
			a = y->prev;
			if (y->prev->n > y->n)
			{
				if (y->next)
					y->next->prev = a;
				if (a->prev)
					a->prev->next = y;
				a->next = y->next;
				y->prev = a->prev;
				a->prev = y;
				y->next = a;
				if (!y->prev)
					*list = y;
				print_list((const listint_t *)*list);
			}
			else
				y = y->prev;
		}
	}
}
