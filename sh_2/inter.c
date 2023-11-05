#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{int re;
	char in[BUFFER_SIZE], *prompt, **arg, *line;

	re = -1;
	prompt = "$ ";
	while (re == -1)

	{
		write(STDOUT_FILENO, prompt, 2);

		line =  get_line();
		strcpy(in, line);
		free(line);
		arg = str_tok(in);
		if (check(arg) == 0)
			continue;
		re = my_fork(arg);
		free(arg);

		if (re >= 0)
			exit(re); }}
