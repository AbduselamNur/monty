#include "monty.h"
stack_t *head = NULL;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	_free();
	return (0);
}

