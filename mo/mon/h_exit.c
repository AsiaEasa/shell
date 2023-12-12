#include "monty.h"

/**
 * _free- free a list
 * @ptr: pointer to first node
 *
 */
void _free(stack_t *ptr)
{
	int i;
	stack_t *tmp;

	for (i =0; head != NULL; i++)
	{
		tmp = ptr->next;
		free(ptr);
		pte = tmp;
	}
}

/**
 * handle_exit - frees the stack and exits due to erro
 * @buff: pointer to the head of the stack
 *
 */
void handle_exit(stack_t **buff)
{
	if (*buff)
		_free(*buff);
	exit(EXIT_FAILURE);
}
