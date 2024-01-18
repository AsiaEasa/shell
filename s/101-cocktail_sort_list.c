#include "sort.h"

/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @a: The first node to swap.
 * @b: The second node to swap.
 */

void swap(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;
	
	a->next = b->next;
	b->prev = a->prev;
	
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ta, *sh;
	int x = 0;

	if (!list || !(*list) || !((*list)->next))
		return;

	ta = *list;
	while (ta->next)
		ta = ta->next;

	while (!x)
	{
		x = 1;
		sh = *list;
		for (; sh != ta; sh = sh->next)
		{
			if (sh->next->n < sh->n)
			{
				swap(list, sh, sh->next);
				print_list((const listint_t *)*list);
				x = 0;
			}
		}
		
		sh = ta;
		for (; sh != *list; sh = sh->prev)
		{
			if (sh->prev->n > sh->n)
			{
				swap(list, sh->prev, sh);
				print_list((const listint_t *)*list);
				x = 0;
			}
		}
	}
}
