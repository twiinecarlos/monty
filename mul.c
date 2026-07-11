#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	temp->next->n = temp->next->n * temp->n;

	*stack = temp->next;
	(*stack)->prev = NULL;

	free(temp);
}
