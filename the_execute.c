#include "monty.h"
/**
* the_execute - execute opcode
* @stack: the head linked list stack
* @counter: the line_counter
* @file: ptr to the monty file
* @content: the line content
* Return:
*/
int the_execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", the_push}, {"pall", the_pall}, {"pint", the_pint},
				{"pop", the_pop},
				{"swap", the_swap},
				{"add", the_add},
				{"nop", the_nop},
				{"sub", the_sub},
				{"div", the_div},
				{"mul", the_mul},
				{"mod", the_mod},
				{"pchar", the_pchar},
				{"pstr", the_pstr},
				{"rotl", the_rotl},
				{"rotr", the_rotr},
				{"queue", the_queue},
				{"stack", the_stack},
				{NULL, NULL}
				};
	unsigned int ix = 0;
	char *opp;

	opp = strtok(content, " \n\t");
	if (opp && opp[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[ix].opcode && opp)
	{
		if (strcmp(opp, opst[ix].opcode) == 0)
		{	opst[ix].f(stack, counter);
			return (0);
		}
		ix++;
	}
	if (opp && opst[ix].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opp);
		fclose(file);
		free(content);
		the_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
