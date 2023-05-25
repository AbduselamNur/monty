#include "monty.h"

void err(int error_code, ...)
{
	va_list x;
	int num;
	char *opc;

	va_start(x, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(x, char *));
			break;
		case 3:
			num = va_arg(x, int);
			opc = va_arg(x, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, opc);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(x, int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}
void string_err(int error_code, ...)
{
        va_list x;
        int num;

        va_start(x, error_code);
        num = va_arg(x, int);
        switch (error_code)
        {
                case 10:
                        fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
                        break;
                case 11:
                        fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
                        break;
                default:
                        break;
        }
        _free();
        exit(EXIT_FAILURE);
}
void more_err(int error_code, ...)
{
	va_list x;
	char *opc;
	int num;

	va_start(x, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(x, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(x, int));
			break;
		case 8:
			num = va_arg(x, unsigned int);
			opc = va_arg(x, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, opc);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(x, unsigned int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}

