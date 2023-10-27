#include "hsh.h"

/**
 * main - Entry point for the custom shell program.
 * @argc: Number of arguments provided.
 * @argv: Array of command-line arguments.
 * Return: Exit status.
 */

int main(int argc, char *argv[])
{int ex, enough;
	char in[BUFFER_SIZE], *_path, *prompt, **arg, *line;
	struct stat stat_in;
	(void) argc, (void) argv;

	enough = 1;
	prompt = "$ ";
	while (enough)

	{
		if (isatty(STDIN_FILENO) == 0)
			enough = 0;
		else

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
		{ _path = arg[0];
		my_fork(arg, _path); }
	free(arg);}
	return (0); }
