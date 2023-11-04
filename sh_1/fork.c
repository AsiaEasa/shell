#include "hsh.h"

/**
 * my_fork -handles the fork
 * Return: Nothing If successful or error if it fails.
 * @arg: Arguments passed to the shell program.
 * @path: correct path of input command
 */

int my_fork(char **arg, char *path)
{
	pid_t child_ID;
	int ID_status;

	child_ID = fork();

	if (child_ID == -1)
	{ free_all(arg);
		free(path);
		perror("Error forking process");
		exit(EXIT_FAILURE); }

	if (child_ID == 0)
		execve(path, arg, NULL);

	if (waitpid(child_ID, &ID_status, 0) == -1)
	{ free_all(arg);
		free(path);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	return (-1);
}
