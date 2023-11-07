#include "hsh.h"
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * set - Entry point for the custom shell program.
 * @variable: variable in environment
 * @value: value of variable in environment
 * Return: change environment
 */
int _setenv(char *name, char *value)
{
	char **ep = environ;
    char *buf = NULL;
    size_t name_len, value_len;

    if (!name) {
        perror("setenv");
        return -1;
    }

    name_len = strlen(name);
    value_len = value ? strlen(value) : 0;

    for (; *ep; ep++) {
        if (!strncmp(*ep, name, name_len) && *(*ep + name_len) == '=') {
            break;
        }
    }

    if (!*ep) {
        ep = (char **) realloc(environ, (sizeof(char *) * (1 + nelem(environ))));
        if (!ep) {
            perror("setenv");
            return -1;
        }
        environ = ep;
        ep = environ + nelem(environ) - 1;
    }

    if (value) {
        buf = (char *) malloc(name_len + value_len + 2);
        if (!buf) {
            perror("setenv");
            return -1;
        }
        sprintf(buf, "%s=%s", name, value);
    }

    free(*ep);
    *ep = buf;

    return 0;
}
