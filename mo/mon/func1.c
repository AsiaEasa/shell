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
 * delete_dnodeint_at_index - Deletes a node from
 * a dlistint_t at a given index.
 * @head: A pointer to the head of the dlistint_t.
 *
 * @index: The index of the node to delete.
 *
 * Return: Upon success = 1.
 * otherwise = -1.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (temp == NULL)
			return (-1);
		temp = temp->next;
	}

	if (temp == *head)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		temp->prev->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}

	free(temp);
	return (1);
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
		return (*head);
	}

	while (end->next != NULL)
	{
		end = end->next;
	}
	list->prev = end;
	end->next = list;

	return (list);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void _free(stack_t *head)
{
	int i;
	stack_t *tmp;

	for (i =0; head != NULL; i++)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
