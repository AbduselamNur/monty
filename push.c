#include "monty.h"

void _push(stack_t **node, __attribute__((unused))unsigned int ln)
{
	stack_t *new;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	new = head;
	head = *node;
	head->next = new;
	new->prev = head;
}
