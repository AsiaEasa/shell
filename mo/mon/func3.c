#include "monty.h"
/**
 * open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */
void open_file(char *file_name, stack_t **buff)
{ int check;
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{ 	fprintf(stderr, "Error: Can't open file %s\n", file_name);
		handle_exit(buff); }

	get(fd, buff);
	check = fclose(fd);
	if (check == -1)
		exit(-1);
}

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 *
 */
int get(FILE *file, stack_t **buff)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int read;
	
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			handle_exit(buff);
		}
		s(buff, line_count);
		line_count++;
	}
	free(buffer);
	return(0);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
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
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

#include "monty.h"

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}
