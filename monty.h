#ifndef _MONTY_H
#define _MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*USES FUNC PROTOCOLE*/

void err(int error_code, ...);
void string_err(int error_code, ...);
void more_err(int error_code, ...);

stack_t *create_node(int n);
void _free(void);
void add_queue(stack_t **, unsigned int);

void c_fun(op_func, char *, char *, int, int);

void openFile(char *name);
int len_chars(FILE *);
void f_func(char *, char *, int, int);
int p_line(char *, int, int);
void readFile(FILE *name);

/*MONTY COMMAND */
void _pall(stack_t **, unsigned int);
void _push(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);

#endif
