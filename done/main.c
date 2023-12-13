#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: always 0
 */
int main(int ac, char **av)
{
	char *err;

	err = "USAGE: monty file\n";
	if (ac != 2)
	{
		write(2, err, _strlen(err));
		exit(EXIT_FAILURE);
	}
	o_file(av[1]);
	_free(head);
	return (0);
}
