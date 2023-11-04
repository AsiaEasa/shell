#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{int ex, enough;
	char in[BUFFER_SIZE], *_path, *prompt, **arg, *line;
	struct stat stat_in;
	(void) argc, (void) argv;

	prompt = "$ ";
	while (enough)

	{
			write(STDOUT_FILENO, prompt, 2);

		line =  my_getline();
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
			my_fork(arg, _path);
			free(_path);}
		else
		{_path = arg[0];
			my_fork(arg, _path);}

		free(arg);}
	return (0); }
