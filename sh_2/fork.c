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

	child_ID = fork();

	if (child_ID == -1)
	{	perror("Error forking process"); }

	else if (child_ID == 0)
	{ if (execvp(arg[0], arg) == -1)
		{
			perror("error in new_process: child process");
		}
	exit(EXIT_FAILURE);}

		else
	waitpid(child_ID, &ID_status, 0);

	return (-1);
}
