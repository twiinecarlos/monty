#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list node
 * @n: integer
 * @prev: previous node
 * @next: next node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* global argument for push */
extern char *value;

/* functions */
void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number);

void execute(char *opcode, stack_t **stack, unsigned int line);
void read_file(FILE *file, stack_t **stack);

int is_integer(char *str);
void free_stack(stack_t *stack);

#endif
