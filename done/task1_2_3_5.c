#include "monty.h"

/**
 * handle_pint - print int in a top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode
 *
 */
void handle_pint(stack_t **buff, unsigned int l_num)
{
	stack_t *print;

	print = *buff;
	if (print == NULL || *buff == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
		handle_exit(buff);
	}
	printf("%d\n", print->n);
}

/**
 * handle_swap - Swaps the top two elements of the stack.
 * @buff: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */

void handle_swap(stack_t **buff, unsigned int l_num)
{
	stack_t *print;
	int tmp;

	print = *buff;
	if (*buff == NULL || print->next == NULL || buff == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_num);
		handle_exit(buff);
	}
	tmp = print->n;
	print->n = print->next->n;
	print->next->n = tmp;
}

/**
 * handle_pop - delete item at top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 */
void handle_pop(stack_t **buff, unsigned int l_num)
{
	stack_t *tmp;

	if (buff == NULL || *buff == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
		handle_exit(buff);
	}
	tmp = *buff;
	*buff = tmp->next;
	if (*buff != NULL)
		(*buff)->prev = NULL;
	free(tmp);
}

/**
 * handle_nop - literally does nothing
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_nop(__attribute__ ((unused))stack_t **buff,
		__attribute__ ((unused))unsigned int l_num)
{
	;
}
