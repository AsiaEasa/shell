#include "monty.h"
/**
 * o_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */
void o_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{ fprintf(stderr, "Error: Can't open file %s\n", file_name);
		handle_exit(&head); }

	get(fd);
	fclose(fd);
}

/**
 * get - reads a bytecode file and runs commands
 * @file: pointer to file
 * Return: zero
 */
int get(FILE *file)
{int l_num, f = 0;
	char *buff = NULL;
	size_t len = 0;

	l_num = 1;
	while (getline(&buff, &len, file) != -1)
	{
		f = p_line(buff, l_num, f);
	l_num++; }
	free(buff);
	return (0);
}
/**
 * op_func -  checks opcode and returns the correct function
 * @op: opcode
 * @val: argument of opcode
 * @f:  storage format. If 0 Nodes will be entered as a stack.
 * @l_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void op_func(char *op, char *val, int l_num, int f)
{
	int i, q_or_s;

	instruction_t instruct[] = {
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_add},
		{"sub", handle_sub},
		{"mul", handle_mul},
		{"div", handle_div},
		{"mod", handle_mod},
		{"nop", handle_nop},
		{"pchar", handle_pchar},
		{"pstr", handle_pstr},
		{"rotl", handle_rotl},
		{"rotr", handle_rotr},
		{NULL, NULL},
	};
	if (op[0] == '#')
		return;
	if (strcmp(op, "push") == 0)
	{
		handle_push(instruct[14].f, op, val, l_num, f);
		q_or_s = 0;
	}
	else
		for (q_or_s = 1, i = 0; instruct[i].opcode != NULL; i++)
		{
			if (strcmp(op, instruct[i].opcode) == 0)
			{
				handle_push(instruct[i].f, op, val, l_num, f);
				q_or_s = 0;
			}
		}
	if (q_or_s == 1)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
		handle_exit(&head); }
}
/**
 * p_line - parses a line for an opcode and arguments
 * @buff: the line to be parsed
 * @l_num: line number
 * @f:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: returns the opcode or null on failure
 */
int p_line(char *buff, int l_num, int f)
{
	char *op, *val;

	if (buff == NULL)
	{ fprintf(stderr, "Error: malloc failed\n");
		handle_exit(&head); }
	op = strtok(buff, "\n ");
	if (op == NULL)
		return (f);
	val = strtok(NULL, "\n");

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	op_func(op, val, l_num, f);
	return (f);
}
