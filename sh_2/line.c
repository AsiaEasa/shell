#include "hsh.h"

/**
 * _read - read a line from the stream
 *
 * Return: pointer that points the the read line
 */

char *_read(void)
{
	int j, c;
	char *line;

	j = 0;
	line = malloc(sizeof(char) * BUFFER_SIZE);

	if (line == NULL)
	{
		write(1, "error in read\n", 14);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			line[j] = '\0';
			return (line);
		}
		else
		{
			line[j] = c;
		}
		j++;
	}
}
