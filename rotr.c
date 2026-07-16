#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
        stack_t *last;

        (void)line_number;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                return;

        last = *stack;

        while (last->next)
                last = last->next;

        last->prev->next = NULL;
        last->prev = NULL;
        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
}
