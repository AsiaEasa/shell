#include "hsh.h"

/**
 * envi -handles the env built-in command
 *@env_word: Arguments for the env command
 *Return: Nothing
 */

int envi(char **env_word)
{ char **ptr, newline;
	char *env;
	char *_env;

	ptr = environ;

	if (!env_word[1])
	{
		while (*ptr)
		{
			print_env(*ptr);
			print_env("\n");
			ptr++; }
		return (1);  }

	else if (env_word[1])
	{ env = env_word[1];
		++env;
		_env = in_env(env);
		write(1, _env, _strlen(_env));
		newline = '\n';

		write(1, &newline, 1);
		return (1); }

	else if (env_word[2])
	{ perror("Error (number of argument is not correct)");
		exit(EXIT_FAILURE); }

	else
		return (0); }
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

/**
 *in_env - gets the value of a speficied environment variable
 * @in_env: Variable to look for in environment
 * Return: Pointer to start index of the value.
 */

char *in_env(char *in_env)
{
	char **ptr = environ;
	int len = _strlen(in_env);

	while (*ptr)
	{

		if (_strncmp(*ptr, in_env, len) == 0 && (*ptr)[len] == '=')
		{
			return (&((*ptr)[len + 1]));
		}
		ptr++;
	}
	return (NULL);
}
