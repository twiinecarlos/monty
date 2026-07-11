#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *last;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = first;

	while (last->next)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}
