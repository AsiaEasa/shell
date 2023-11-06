#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{int re;
	char *prompt, **arg, in[BUFFER_SIZE], *line;

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
		handle_cd(arg);
		re = my_fork(arg);
		free(arg);

		if (re >= 0)
			exit(re); }}
