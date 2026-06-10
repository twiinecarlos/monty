#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - carries shared interpreter state
 * @filename: path to the bytecode file
 * @fp: open file pointer
 * @line: current line buffer
 * @push_arg: argument string for push opcode
 *
 * Description: global state bag passed between interpreter helpers
 */
typedef struct bus_s
{
	char *filename;
	FILE *fp;
	char *line;
	char *push_arg;
} bus_t;

/* opcode functions */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

/* interpreter helpers */
void free_stack(stack_t *stack);
void run_line(stack_t **stack, unsigned int line_number);
void run_file(void);

/* global bus */
extern bus_t bus;

#endif /* MONTY_H */
