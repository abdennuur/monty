#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack or queue
 * @n: int
 * @prev: pts to previous element of the stack or queue
 * @next: pts to next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack  queues  LIFO  FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - the opcode and its function
 * @opcode: opcode
 * @f: function to handle the opcode
 *
 * Description: the opcode and its function
 * for the stack queues LIFO FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*the file operations*/
void the_open_file(char *file_name);
int the_parse_line(char *buffer, int line_number, int format);
void the_read_file(FILE *);
int the_len_chars(FILE *);
void the_find_func(char *, char *, int, int);

/*the Stack operations*/
stack_t *create_node(int n);
void the_free_nodes(void);
void the_print_stack(stack_t **, unsigned int);
void the_add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void the_print_top(stack_t **, unsigned int);
void the_pop_top(stack_t **, unsigned int);
void the_nop(stack_t **, unsigned int);
void the_swap_nodes(stack_t **, unsigned int);

/*Maths operations with nodes*/
void the_add_nodes(stack_t **, unsigned int);
void the_sub_nodes(stack_t **, unsigned int);
void the_div_nodes(stack_t **, unsigned int);
void the_mul_nodes(stack_t **, unsigned int);
void the_mod_nodes(stack_t **, unsigned int);

/*the Str Operations*/
void the_print_char(stack_t **, unsigned int);
void the_print_str(stack_t **, unsigned int);
void the_rotl(stack_t **, unsigned int);

/*the Errors hanlding*/
void the_err(int error_code, ...);
void the_more_err(int error_code, ...);
void the_string_err(int error_code, ...);
void the_rotr(stack_t **, unsigned int);

#endif
