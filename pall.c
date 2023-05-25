#include "monty.h"
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	new = *stack;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

