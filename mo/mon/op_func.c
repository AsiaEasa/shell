#include "monty.h"
/**
 * open_file - opens a file
 * @file_name: the file namepath
 * @buff: pointer to the top of the stack
 * Return: void
 */
void open_file(char *file_name, stack_t **buff)
{ int check;
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{ fprintf(stderr, "Error: Can't open file %s\n", file_name);
		handle_exit(buff); }

	get(fd, buff);
	check = fclose(fd);
	if (check == -1)
		exit(-1);
}

/**
 * get - reads a bytecode file and runs commands
 * @file: pointer to file
 * @buff: pointer to the top of the stack
 * Return: zero
 */
int get(FILE *file, stack_t **buff)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func st;
	int read;

	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = p_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		st = op_func(line);
		if (st == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			handle_exit(buff);
		}
		st(buff, line_count);
		line_count++;
	}
	free(buffer);
	return (0);
}
/**
 * op_func -  checks opcode and returns the correct function
 * @ptr: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func op_func(char *ptr)
{
	int i;

	instruction_t instruct[] = {
		{"push", handle_push},
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
		{"stack", is_stack},
		{"queue", is_queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && _strcmp(instruct[i].opcode, ptr) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * p_line - parses a line for an opcode and arguments
 * @buffer: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *p_line(char *buffer)
{
	char *op;

	if (buffer == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	op = strtok(buffer, "\n ");
	if (op == NULL)
		return (NULL);
	return (op);
}
