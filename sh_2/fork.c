#include "hsh.h"

/**
 * my_fork -handles the fork
 * Return: Nothing If successful or error if it fails.
 * @arg: Arguments passed to the shell program.
 * @path: correct path of input command
 */

int my_fork(char **arg)
{
	pid_t child_ID;
	int ID_status;
	if (access(arg[0], F_OK) != -1)
	{ child_ID = fork();

		if (child_ID == -1)
		{ free_all(arg);
			perror("Error forking process");
			exit(EXIT_FAILURE); }

		if (child_ID == 0)
			if (execvp(arg[0], arg) == -1)
				error(arg[0]);

		if (waitpid(child_ID, &ID_status, 0) == -1)
		{ free_all(arg);
			perror("Command not found");
			exit(127);
		}
		return (-1); }
	error(arg[0]);
	exit(127); }
