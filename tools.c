#include "monty.h"

void f_func(char *opcode, char *val, int ln, int form)
{
	int x, fl;

	instruction_t flist[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fl = 1, x = 0; flist[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, flist[x].opcode) == 0)
		{
			c_fun(flist[x].f, opcode, val, ln, form);
			fl = 0;
		}
	}
	if (fl == 1)
		err(3, ln, opcode);
}
void c_fun(op_func func, char *op, char *val, int ln, int form)
{
	stack_t *node;
	int fl;
	int x;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * fl);
		if (form == 0)
			func(&node, ln);
		if (form == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
int p_line(char *buf, int ln, int form)
{
        char *opcode;
        char *val;
        const char *deli = "\n ";

        if (buf == NULL)
                err(4);

        opcode = strtok(buf, deli);
        if (opcode == NULL)
                return (form);
        val = strtok(NULL, deli);

        if (strcmp(opcode, "stack") == 0)
                return (0);
        if (strcmp(opcode, "queue") == 0)
                return (1);

        f_func(opcode, val, ln, form);
        return (form);
}
