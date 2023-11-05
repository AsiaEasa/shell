#include "hsh.h"

/**
 * envi -handles the env built-in command
 *@env_word: Arguments for the env command
 *Return: Nothing
 */

int envi(void)
{ char **ptr;

	ptr = environ;

		while (*ptr)
		{
			print_env(*ptr);
			print_env("\n");
			ptr++; }
		return (-1);  }

/**
 * print_env - print all environmen
 * @str: point to environment
 * Return: Nothing.
 */

void print_env(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
