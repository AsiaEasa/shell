#include "hsh.h"

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
