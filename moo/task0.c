#include "monty.h"

/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(instruct_func func, char *op, char *val, int ln, int format)
{
	int flag;
	int i;
	int p;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				fprintf(stderr, "L%d: usage: push integer\n", ln);
		}
		p = atoi(val);
		p *= flag;
		if (format == 0)
			add_dnodeint(&head, p);
		if (format == 1)
			add_dnodeint_end(&head, p);
	}
	else
		func(&head, ln);
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
