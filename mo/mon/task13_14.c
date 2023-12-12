#include "monty.h"
/**
 * handle_rotl - rotates the list left
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_rotl(stack_t **buff, __attribute__ ((unused))unsigned int l_num)
{
	stack_t *step;
	int num1, num2;

	if (buff == NULL || *buff == NULL || (*buff)->next == NULL)
		return;
	step = *buff;
	while (step->next)
		step = step->next;
	while (step)
	{
		if (!step->next)
		{
			num1 = step->n;
			step->n = (*buff)->n;
		}
		else
		{
			num2 = step->n;
			step->n = num1;
			num1 = num2;
		}
		step = step->prev;
	}
}
/**
 * handle_rotr - rotates the list right
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_rotr(stack_t **buff, __attribute__ ((unused))unsigned int l_num)
{
	stack_t *step1, *step2;
	int num1, num2;

	if (buff == NULL || *buff == NULL || (*buff)->next == NULL)
		return;

	step1 = *buff;
	step2 = *buff;
	while (step1->next)
		step1 = step1->next;
	while (step2)
	{
		if (step2->prev == NULL)
		{
			num1 = step2->n;
			step2->n = step1->n;
		}
		else
		{
			num2 = step2->n;
			step2->n = num1;
			num1 = num2;
		}
		step2 = step2->next;

	}
}
