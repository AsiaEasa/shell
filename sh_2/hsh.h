#ifndef HSH_H
#define HSH_H
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
void _puts(char *str);
int _strncmp(char *str1, char *str2, int n);
int _putchar(char c);
char *read_line(void);
void free_all(char **arg);
int check(char **arg);
int _strcmp(char *s1, char *s2);
char *get_line(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
int my_fork(char **arg);
int handle_exit(char **exit_args);
extern char **environ;
int envi(void);
void print_env(char *str);
char **str_tok(char *line);
char *_strcat(char *dest, char *src);
void interactive(void);
void none_interactive(void);
int main(void);
#endif
