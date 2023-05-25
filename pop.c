#include "monty.h"
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (*stack == NULL || stack == NULL)
		more_err(7, line_number);
	new = *stack;
	*stack = new->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(new);
}
