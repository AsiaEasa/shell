#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int q_or_s;
/*Struct Definitions*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/*task0*/
void handle_push(stack_t **buff, unsigned int l_number);
void handle_pall(stack_t **buff, unsigned int l_num);
void is_stack(stack_t **buff, unsigned int l_num);
void is_queue(stack_t **buff, unsigned int l_num);
/*task1_2_3_5*/
void handle_pint(stack_t **buff, unsigned int l_num);
void handle_swap(stack_t **buff, unsigned int l_num);
void handle_pop(stack_t **buff, unsigned int l_num);
void handle_nop(stack_t **buff, unsigned int l_num);
/*task4_6*/
void handle_add(stack_t **buff, unsigned int l_num);
void handle_sub(stack_t **buff, unsigned int l_num);
/*task7_8_9*/
void handle_mul(stack_t **buff, unsigned int l_num);
void handle_div(stack_t **buff, unsigned int l_num);
void handle_mod(stack_t **buff, unsigned int l_num);
/*task11_12*/
void handle_pchar(stack_t **buff, unsigned int l_num);
void handle_pstr(stack_t **buff, __attribute__ ((unused))unsigned int l_num);
/*task13_14*/
void handle_rotl(stack_t **buff, __attribute__ ((unused))unsigned int l_num);
void handle_rotr(stack_t **buff, __attribute__ ((unused))unsigned int l_num);
/*h_exit*/
void _free(stack_t *ptr);
void handle_exit(stack_t **buff);
/*op_node*/
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
/*op_func*/
void open_file(char *file_name, stack_t **buff);
int get(FILE *file, stack_t **buff);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
char *p_line(char *line);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
instruct_func op_func(char *str);
/*str1*/
int isnumber(char *str);
int _isdigit(int c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
/*str2*/
int _atoi(char *s);
int _putchar(char c);
#endif
