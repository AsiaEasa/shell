#include "sort.h"

/**
 * swap - Swap two nodes in doubly-linked list.
 * @x: A pointer to the first node.
 * @y:  A pointer to the second node.
 */

void swap(listint_t *x, listint_t *y)
{
	if (y->next)
		y->next->prev = x;
	if (x->prev)
		x->prev->next = y;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
 * insertion_sort_list - insertion to sort a doubly linked list
 *
 * @list: the address of the node (head)
 *
 * Return: nothing (void)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y;

	if (!list || !*list || !(*list)->next)
		return;
	x = (*list)->next;
	while (x)
	{
		y = x;
		x = x->next;
		while (y && y->prev)
		{
			if (y->prev->n > y->n)
			{
				
				swap(y->prev, y);
				if (!y->prev)
					*list = y;
				print_list((const listint_t *)*list);
			}
			else
				y = y->prev;
		}
	}
}
