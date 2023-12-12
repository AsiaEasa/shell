#include "monty.h"
int q_or_s = 0;
/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: always 0
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
