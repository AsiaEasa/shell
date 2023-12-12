#include "monty.h"

/**
 * handle_mul - multiply top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode
 *
 */
void handle_mul(stack_t **buff, unsigned int l_num)
{
	if (buff == NULL || *buff == NULL || (*buff)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n *= (*buff)->n;
	handle_pop(buff, l_num);
}

/**
 * handle_div - divide top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode
 */
void handle_div(stack_t **buff, unsigned int l_num)
{
	if (buff == NULL || *buff == NULL || (*buff)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_num);
		handle_exit(buff);
	}
	if ((*buff)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n /= (*buff)->n;
	handle_pop(buff, l_num);
}

/**
 * handle_mod - mod top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode
 *
 */
void handle_mod(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL || buff == NULL || (*buff)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_num);
		handle_exit(buff);
	}
	if ((*buff)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n %= (*buff)->n;
	handle_pop(buff, l_num);
}
