#include "monty.h"
/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
