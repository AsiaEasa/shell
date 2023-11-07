#include "hsh.h"

/**
 * check - to check what is the input
 * @arg: array of command
 * Return: exit
 */

int check(char **arg)
{if (_strncmp(arg[0], "cd", 2) == 0)
				     { cd(arg);
				       free(arg);
				  return(0);}
				       if (_strncmp(arg[0], "exit", 4) == 0)
		handle_exit(arg);

	if (_strncmp(arg[0], "env", 3) == 0 || _strncmp(arg[0], "printenv", 4) == 0)
	{ envi();
		free(arg);
		return (0); }

	if (_strcmp(arg[0], "setenv") == 0) {
           if (arg[1] != NULL && arg[2] != NULL) {            set(arg[1], arg[2]);
free(arg);
	   return (0); }
	   else {
                perror("Invalid setenv command syntax.");
            }}
	return (1); }
