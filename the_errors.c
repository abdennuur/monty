#include "monty.h"

/**
 * the_err - Print appropiate error messages determined by their error code
 * @error_code: The error codes -> following
 * 1 -> user does not give any file or more than one file to the program.
 * 2 ->  file provided is not a file that can be opened or read.
 * 3 ->  file provided contains an invalid instruction.
 * 4 ->  the program is unable to malloc more memory.
 * 5 -> the parameter passed to instruction "push" is not an int.
 * 6 ->  the stack it empty for pint.
 * 7 -> the stack it empty for pop.
 * 8 -> stack is too short for operation.
 */
void the_err(int error_code, ...)
{
	va_list agg;
	char *opp;
	int l_nm;

	va_start(agg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agg, char *));
			break;
		case 3:
			l_nm = va_arg(agg, int);
			opp = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_nm, opp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(agg, int));
			break;
		default:
			break;
	}
	the_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * the_more_err - handle error
 * @error_code: The error codes following:
 * 6 ->  the stack empty for pint.
 * 7 ->  the stack  empty for pop.
 * 8 ->  stack too short for operation.
 * 9 -> Div by zero
 */
void the_more_err(int error_code, ...)
{
	va_list agg;
	char *opp;
	int l_nm;

	va_start(agg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agg, int));
			break;
		case 8:
			l_nm = va_arg(agg, unsigned int);
			opp = va_arg(agg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_nm, opp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agg, unsigned int));
			break;
		default:
			break;
	}
	the_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * the_string_err - handle errors
 * @error_code:error cosses  following:
 * 10 -> number inside node  outside ASCII bounds.
 * 11 -> The stack is empty.
 */
void the_string_err(int error_code, ...)
{
	va_list agg;
	int l_nm;

	va_start(agg, error_code);
	l_nm = va_arg(agg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_nm);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_nm);
			break;
		default:
			break;
	}
	the_free_nodes();
	exit(EXIT_FAILURE);
}
