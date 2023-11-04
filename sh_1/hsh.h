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
#define MAX_COMMAND_LENGTH 100
void _puts(char *str);
int _putchar(char c);
char *read_line(void);
void free_all(char **arg);
int check(char **arg);
int _strcmp(char *s1, char *s2);
void set(char *variable, char *value);
void unset(char *variable);
char *get_line(void);
void chDir(char *directory);
char *_strdup(char *str);
char *_strchr(char *s, char c);
int _strlen(char *s);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
int my_fork(char **arg, char *path);
int handle_exit(char **exit_args);
char *Path(char *command);
extern char **environ;
int envi(char **env_word);
void print_env(char *str);
char *in_env(char *in_env);
char **str_tok(char str[BUFFER_SIZE], char separate);
char *_strcat(char *dest, char *src);
void interactive(void);
void none_interactive(void);
char *str_concat(char *word1, char *word2, char *word3);
int main(void);
#endif
