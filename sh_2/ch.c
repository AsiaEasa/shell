#include "hsh.h"

void cd(char **arg) {
	char cwd[1024];
	char *path;
	path = arg[1];

	if (path == NULL) {
		char *home = getenv("HOME");
		chdir(home); }

	else if (strcmp(path, "-") == 0) {
		char *oldpwd = getenv("OLDPWD");
		if (oldpwd == NULL) {
			fprintf(stderr, "OLDPWD environment variable not set\n");
			return;
		}
		_puts(oldpwd);
		_putchar('\n');
		if (chdir(oldpwd) == -1) {
			perror("chdir");
		}
	} else
{
		if (chdir(path) == -1) {
		ch_er(path); }
	}
	if (getenv("PWD") != NULL) {
		putenv("PWD");
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		setenv("PWD", cwd, 1);
	}
}
