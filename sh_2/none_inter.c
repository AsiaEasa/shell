#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void none_interactive(void)
{int re;
	char in[SBUFFE_RIZE], **arg, *line;

	re = -1;
	while (re == -1)

	{
		line =  read_line();
		strcpy(in, line);
		free(line);
		arg = str_tok(in);

		if (check(arg) == 0)
		{
			continue; }

			re = my_fork(arg);
			free(arg);

		if (re >= 0)
		{
			exit(re); }}}
