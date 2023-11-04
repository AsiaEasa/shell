#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{int ex, re;
	char in[BUFFER_SIZE], *_path, *prompt, **arg, *line;
	struct stat stat_in;

	re = -1;
	prompt = "$ ";
	while (re == -1)

	{
		write(STDOUT_FILENO, prompt, 2);

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
				perror("./hsh");
				continue; }
			re = my_fork(arg, _path);
			free(_path);}
		else
		{_path = arg[0];
			re = my_fork(arg, _path);}

		free(arg);

		if (re >= 0)
			exit(re); }}
