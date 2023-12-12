#include "monty.h"
/**
 * handle_push - to push int to a stack
 * @buff: linked lists for monty stack
 * @l_num: number of line
 */
void handle_push(stack_t **buff, unsigned int l_num)
{
	char *token, *m;
	stack_t *new;
	int new_push;

	m= "Error: malloc failed\n";
	new_push = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		write(2, m, _strlen(m));
		handle_exit(buff);
	}

	token = strtok(NULL, "\n ");
	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_num);
		handle_exit(buff);
	}

	if (isnumber(token) == 1 && token != NULL)
	{
		new_push = _atoi(token);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_num);
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
void handle_pall(stack_t **buff, unsigned int l_num)
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
