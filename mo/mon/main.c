#include "monty.h"
int q_or_s = 0;
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *buff;
	char *err;

	err = "USAGE: monty file\n";
	buff = NULL;
	if (ac != 2)
	{
		write(2, err, strlen(err));
		handle_exit(&buff);
	}
	get(av[1], &buff);
	_free(buff);
	return (0);
}
