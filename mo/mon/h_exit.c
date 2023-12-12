#include "monty.h"

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

/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void handle_exit(stack_t **stack)
{
	if (*stack)
		_free(*stack);
	exit(EXIT_FAILURE);
}
