#include "monty.h"

char mode = 's';

/**
 * stack_mode - sets stack mode
 * @stack: stack
 * @line_number: line number
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = 's';
}

/**
 * queue_mode - sets queue mode
 * @stack: stack
 * @line_number: line number
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = 'q';
}
