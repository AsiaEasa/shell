#include "hsh.h"

void handle_cd(char **arg)
{long size;
	char *home_directory = in_env("HOME");
	char *buf;
	if (home_directory == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	size = pathconf(".", _PC_PATH_MAX);
	if ((buf = (char *)malloc((size_t)size)) != NULL)
		if (getcwd(buf, (size_t)size) == NULL)
		{ free(arg);
			perror("getcwd");
			exit(EXIT_FAILURE);
		}

	if ( arg[1] || strncmp(arg[1], "~", 1) == 0) 
	{
		if (chdir(home_directory) != 0)
			perror("chdir");
		else {
			if (setenv("PWD", home_directory, 1) != 0)
			{ free(arg);
				perror("setenv");
				exit(EXIT_FAILURE);
			}
		}}
	else
	{if (strncmp(arg[1], "-", 1) == 0) {
						   if (chdir(buf) != 0) {
							   perror("chdir");
						   } else {
							   if (setenv("PWD", buf, 1) != 0)
								   perror("setenv");
						   }
					   }}
	free(home_directory);
}
