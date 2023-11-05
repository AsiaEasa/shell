#include "hsh.h"

/**
 * my_fork -handles the fork
 * Return: Nothing If successful or error if it fails.
 * @arg: Arguments passed to the shell program.
 * @path: correct path of input command
 */

int my_fork(char **arg)
{

	pid_t PID;
	int stat;

	PID = fork();
	if (PID ==  0)
	{
		if (execvp(arg[0], arg) == -1)
		{ free_all(arg);
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (PID < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(PID, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}

	return (-1); }
