#include "monty.h"

void add_queue(stack_t **node, __attribute__((unused))unsigned int ln)
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
	while (new->next != NULL)
		new = new->next;

	new->next = *node;
	(*node)->prev = new;

}
stack_t *create_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		err(4);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}
void _free(void)
{
	stack_t *new;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new);
	}
}
