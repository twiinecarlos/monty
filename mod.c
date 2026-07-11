#include "monty.h"

/**
 * mod - computes the remainder of division of the second top element
 * by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	temp->next->n = temp->next->n % temp->n;

	*stack = temp->next;
	(*stack)->prev = NULL;

	free(temp);
}
