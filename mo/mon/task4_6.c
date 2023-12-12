#include "monty.h"
/**
 * handle_add - adds top of stack and second top of stack
 *
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode
 */
void handle_add(stack_t **buff, unsigned int l_num)
{
	if (buff == NULL || *buff == NULL || (*buff)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n += (*buff)->n;
	handle_pop(buff, l_num);
}

/**
 * handle_sub - subtracts top of stack and second top of stack
 *
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode
 */
void handle_sub(stack_t **buff, unsigned int l_num)
{
	if (buff == NULL || *buff == NULL || (*buff)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n -= (*buff)->n;
	handle_pop(buff, l_num);
}
