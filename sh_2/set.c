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
void set(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
		perror("Failed to set environment variable"); }
