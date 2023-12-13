#include "monty.h"
/**
 * open_file - opens a file
 * @file_name: the file namepath
 * @buff: pointer to the top of the stack
 * Return: void
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{ fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE); }

	get(fd);
	fclose(fd);
}

/**
 * get - reads a bytecode file and runs commands
 * @file: pointer to file
 * @buff: pointer to the top of the stack
 * Return: zero
 */
int get(FILE *file)
{int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, file) != -1; line_number++)
	{
		format = p_line(buffer, line_number, format);
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
void op_func(char *opcode, char *value, int ln, int format)
{
	int i, flag;

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
	if (opcode[0] == '#')
		return;
	if (strcmp(opcode, "push") == 0)
	{
		call_fun(instruct[14].f, opcode, value, ln, format);
		flag = 0;
	}
	else
		for (flag = 1, i = 0; instruct[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instruct[i].opcode) == 0)
			{
				call_fun(instruct[i].f, opcode, value, ln, format);
				flag = 0;
			}
		}
	if (flag == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
}
/**
 * p_line - parses a line for an opcode and arguments
 * @buffer: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
int p_line(char *buffer, int line_number, int format)
{
	char *op, *value;

	if (buffer == NULL)
	{ fprintf(stderr, "Error: malloc failed\n");
		return (0); }
	op = strtok(buffer, "\n ");
	if (op == NULL)
		return (format);
	value = strtok(NULL, "\n");

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	op_func(op, value, line_number, format);
	return (format);
}
