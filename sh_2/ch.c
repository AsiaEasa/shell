#include "hsh.h"

void handle_cd(char **arg)
{
	char *home_directory = in_env("HOME");
	char current_directory[MAX_COMMAND];
	char new_directory[MAX_COMMAND];
	if (home_directory == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}

	if (getcwd(current_directory, sizeof(current_directory)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	if (strcmp(arg[0], "cd") == 0) 
	{
		if ( arg[1] || strcmp(arg[1], "~") == 0) 
		{
			if (chdir(home_directory) != 0)
			{
				perror("chdir"); }
			else {
				if (setenv("PWD", home_directory, 1) != 0)
				{
					perror("setenv");
					exit(EXIT_FAILURE);
				}
			}
		} else if (strcmp(arg[1], "-") == 0) {
			if (chdir(current_directory) != 0) {
				perror("chdir");
			} else {
				if (setenv("PWD", current_directory, 1) != 0) {
					perror("setenv");
					exit(EXIT_FAILURE);
				}
			}
		} else {
			if (chdir(arg[1]) != 0) {
				perror("chdir");
			} else {

				if (getcwd(new_directory, sizeof(new_directory)) == NULL) {
					perror("getcwd");
					exit(EXIT_FAILURE);
				}
				if (setenv("PWD", new_directory, 1) != 0) {
					perror("setenv");
					exit(EXIT_FAILURE);
				}
			}
		}
	}}
