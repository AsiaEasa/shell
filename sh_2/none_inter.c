#include "hsh.h"

/**
 * none_interactive - UNIX command line none interpreter
 *
 * Return: void
 */
void none_interactive(void)
{int re;
	char in[BUFFER_SIZE], **arg, *line;

	re = -1;
	while (re == -1)

	{
		line = _read();
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
