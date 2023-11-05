#include "hsh.h"
/**
 * str_tok - a function that spilt the string
 * @str: command input
 * @separate: space separates word
 * Return: string
 */

char **str_tok(char *line)
{ int buffersize, j;
	char **given_tokens;
	char *token;

	buffersize = 64;
	j = 0;
	given_tokens = malloc(buffersize * sizeof(char *));

	if (!given_tokens)
	{
		_puts("allocation error in split_line: tokensi\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		/* handle comments */
		if (token[0] == '#')
		{
			break;
		}
		given_tokens[j] = token;
		j++;
		if (j >= buffersize)
		{
			buffersize += buffersize;
			given_tokens = realloc(given_tokens, buffersize * sizeof(char *));
			if (!given_tokens)
			{
				_puts("reallocation error in split_line: tokens\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	given_tokens[j] = NULL;
	return (given_tokens);
}
/**
 *_strcat - concatenates two string
 * @dest: input value
 * @src: input value
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * str_concat - concatenates three strings
 * @word1: input value
 * @word2: input value
 * @word3: input value
 * Return: void
 */

char *str_concat(char *word1, char *word2, char *word3)
{
	int total_length = _strlen(word1) + _strlen(word2) + _strlen(word3) + 1;
	char *result = malloc(total_length * sizeof(char));

	if (result == NULL)
	{
		return (NULL); }
	_strcpy(result, word1);
	_strcat(result, word2);
	_strcat(result, word3);
	return (result); }
	/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints a string to stdout
 *
 * @str: char pointer variable
 *
 * Return: nothing
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
