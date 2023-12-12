#include "monty.h"

/**
 * is_stack - sets q_or_s to stack
 * @buff: pointer to stack list
 * @l_num: line number opcode occurs
 */
void is_stack(stack_t **buff, unsigned int l_num)
{
	(void) buff, (void) l_num;
	q_or_s = 0;
}
/**
 * is_queue - sets q_or_s to queue
 * @buff: pointer to stack list
 * @l_num: line number opcode occurs
 */
void is_queue(stack_t **buff, unsigned int l_num)
{
	(void) buff, (void) l_num;
	q_or_s = 1;
}
