#include "monty.h"
/**
 * handle_push - to push int to a stack
 * @buff: linked lists for monty stack
 * @l_num: number of line
 */
void handle_push(stack_t **buff, unsigned int l_number)
{
	char *token, *m;
	stack_t *new;
	int new_push;

	m= "Error: malloc failed\n";
	new_push = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		write(2, p, strlen(p));
		handle_exit(buff);
	}

	token = strtok(NULL, "\n ");
	if (isnumber(token) == 1 && token != NULL)
	{
		new_push = atoi(token);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		handle_exit(buff);
	}

	if (q_or_s == 1)
	{
		add_dnodeint_end(buff, new_push);
	}

	if (q_or_s == 0)
	{
		add_dnodeint(buff, new_push);
	}

}
/**
 * handle_pall - print all stak
 * @buff: pointer to linked list stack
 * @l_num: number of line
 */
void handle_pall(stack_t **buff, __attribute__ ((unused))unsigned int l_num)
{
	stack_t *print;
	int i;

	(void) l_num;
	print = *buff;
	if (buff == NULL)
		handle_exit(buff);

	for (i = 0; print != NULL; i++)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

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
