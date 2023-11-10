#include "hsh.h"

/**
 * my_fork -handles the fork
 * Return: Nothing If successful or error if it fails.
 * @arg: Arguments passed to the shell program.
 */
int my_fork(char **arg)
{
	pid_t child_ID;
	int ID_status;

	child_ID = fork();
	if (child_ID ==  0)
	{
		if (execvp(arg[0], arg) == -1)
		{ error(arg[0]);
			return(127);
		}
	}
	else if (child_ID< 0)
		perror("Error forking process");

	else
		waitpid(child_ID, &ID_status, 0);

	return (-1);
}
