#include "monty.h"

/**
 * the_open_file - open file
 * @file_name: file name path
 * Return: 
 */

void the_open_file(char *file_name)
{
	FILE *fid = fopen(file_name, "r");

	if (file_name == NULL || fid == NULL)
		the_err(2, file_name);

	the_read_file(fid);
	fclose(fid);
}


/**
 * the_read_file - read file
 * @fd: ptr to file descriptor
 * Return:
 */

void the_read_file(FILE *fd)
{
	int ln_nbr, format = 0;
	char *buff = NULL;
	size_t ln = 0;

	for (ln_nbr = 1; getline(&buff, &ln, fd) != -1; ln_nbr++)
	{
		format = the_parse_line(buff, ln_nbr, format);
	}
	free(buff);
}


/**
 * the_parse_line - Separate each line into tokens to determine
 * which function calls
 * @buffer: line from file
 * @line_number: the line number
 * @format:  storage format. If 0 -> stack.
 * if 1 -> queue.
 * Return: Returns 0 -> stack. 1 -> queue
 */

int the_parse_line(char *buffer, int line_number, int format)
{
	char *opcd, *val;
	const char *dlm = "\n ";

	if (buffer == NULL)
		the_err(4);

	opcd = strtok(buffer, dlm);
	if (opcd == NULL)
		return (format);
	val = strtok(NULL, dlm);

	if (strcmp(opcd, "stack") == 0)
		return (0);
	if (strcmp(opcd, "queue") == 0)
		return (1);

	the_find_func(opcd, val, line_number, format);
	return (format);
}

/**
 * the_find_func - find appropriate function for opcode
 * @opcode: the opcode
 * @value: arg of opcode
 * @format:  storage format. If 0->stack.
 * @ln: the line number
 * if 1 -> queue.
 * Return:
 */
void the_find_func(char *opcode, char *value, int ln, int format)
{
	int ix;
	int flg;

	instruction_t func_list[] = {
		{"push", the_add_to_stack},
		{"pall", the_print_stack},
		{"pint", the_print_top},
		{"pop", the_pop_top},
		{"nop", the_nop},
		{"swap", the_swap_nodes},
		{"add", the_add_nodes},
		{"sub", the_sub_nodes},
		{"div", the_div_nodes},
		{"mul", the_mul_nodes},
		{"mod", the_mod_nodes},
		{"pchar", the_print_char},
		{"pstr", the_print_str},
		{"rotl", the_rotl},
		{"rotr", the_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, ix = 0; func_list[ix].opcode != NULL; ix++)
	{
		if (strcmp(opcode, func_list[ix].opcode) == 0)
		{
			call_fun(func_list[ix].f, opcode, value, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		the_err(3, ln, opcode);
}


/**
 * call_fun - Call required function
 * @func: ptr to function to be called
 * @op: str representing opcode.
 * @val: str representing  numeric value.
 * @ln: line nbr for instruction
 * @format: Format specifier 0 ->stack.
 * if 1 -> queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *nd;
	int flg;
	int ix;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			the_err(5, ln);
		for (ix = 0; val[ix] != '\0'; ix++)
		{
			if (isdigit(val[ix]) == 0)
				the_err(5, ln);
		}
		nd = create_node(atoi(val) * flg);
		if (format == 0)
			func(&nd, ln);
		if (format == 1)
			add_to_queue(&nd, ln);
	}
	else
		func(&head, ln);
}
