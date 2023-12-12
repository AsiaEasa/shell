#include "monty.h"
/**
 * handle_pchar - prints the ASCII value of a number
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_pchar(stack_t **buff, unsigned int l_num)
{
	int ascii;

	if (buff == NULL || *buff == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		handle_exit(buff);
	}

	ascii = (*buff)->n;

	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
		handle_exit(buff);
	}

	putchar(ascii);
	putchar('\n');
}

/**
 * handle_pstr - print string starting a top of stack
 * @buff: linked list for stack
 * @l_num: line number opcode occurs on
 */
void handle_pstr(stack_t **buff, __attribute__ ((unused))unsigned int l_nun)
{
	stack_t *step;
	int ascii;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	step = *buff;

	while (step != NULL)
	{
		ascii = step->n;
		if (ascii <= 0 || ascii > 127)
			break;
		putchar(ascii);
		step = step->next;
	}
	putchar('\n');
}
