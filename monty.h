#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list stack
 * @n: integer value
 * @prev: previous node
 * @next: next node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode mapping
 * @opcode: command
 * @f: function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* global argument for push */
extern char *arg;

/* functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

int is_integer(char *str);
void free_stack(stack_t *stack);

void execute_line(char *line, stack_t **stack, unsigned int line_number);
void read_file(FILE *file, stack_t **stack);

#endif
