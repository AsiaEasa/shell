#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void none_interactive(void)
{int ex, re;
	char in[BUFFER_SIZE], *_path, **arg, *line;
	struct stat stat_in;

	re = -1;
	while (re == -1)

	{
		line =  read_line();
		strcpy(in, line);
		free(line);
		arg = str_tok(in, ' ');
		if (check(arg) == 0)
			continue;


		ex = stat(arg[0], &stat_in);
		if (ex)

		{ _path = Path(arg[0]);
			if (!_path)
			{free(_path);
				perror("path");
				continue; }
			re = my_fork(arg, _path);
			free(_path);}
		else
		{_path = arg[0];
			re = my_fork(arg, _path);}
		if (re >= 0)
			exit(re); 
	free(arg); }}
