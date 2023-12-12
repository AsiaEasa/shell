#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int q_or_s;
/*--- Struct Definitions ---*/
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
/*task1_2_3*/
void handle_pint(stack_t **buff, unsigned int l_num);
void handle_swap(stack_t **buff, unsigned int l_num);
void handle_pop(stack_t **buff, unsigned int l_num);
/*h_exit*/

typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
char *parse_line(char *line);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
instruct_func get_op_func(char *str);
void get(char *filename, stack_t **stack);
void _nop(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void _free(stack_t *head);
void handle_exit(stack_t **stack);
int isnumber(char *str);
#endif
