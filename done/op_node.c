#include "monty.h"
/**
 * add_dnodeint - Adds a new node at the beginning
 *
 * @head: Head
 *
 * @n: Value
 *
 * Return: dlistint_t
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp, *node = malloc(sizeof(stack_t));


	if (node == NULL)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
		return (node);
	}
	temp = *head;
	node->next = temp;
	temp->prev = node;
	*head = node;
	return (node);
}
/**
 * add_dnodeint_end - Adds a new node at the end
 *
 * @head: struct
 *
 * @n: const int
 *
 * Return: dlistint_t
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *list = NULL, *end = *head;

	list = malloc(sizeof(stack_t));

	if (list == NULL)
	{
		return (NULL);
	}
	list->n = n;
	list->prev = NULL;
	list->next = NULL;

	if (*head == NULL)
	{
		*head = list;
		return (list);
	}

	while (end->next != NULL)
	{
		end = end->next;
	}
	list->prev = end;
	end->next = list;

	return (list);
}
