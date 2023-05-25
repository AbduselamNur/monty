#include "monty.h"
void _pint(stack_t **stack, unsigned int line_number)
{
		if (*stack == NULL || stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
