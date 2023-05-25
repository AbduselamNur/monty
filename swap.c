#include "monty.h"
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	new = (*stack)->next;
	(*stack)->next = new->next;
	if (new->next != NULL)
		new->next->prev = *stack;
	new->next = *stack;
	(*stack)->prev = new;
	new->prev = NULL;
	*stack = new;
}
