#include "monty.h"
/**
 * the_push - add a node to stack
 * @head: the stack head
 * @counter: the line_number
 * Return:
*/
void the_push(stack_t **head, unsigned int counter)
{
	int an, ji = 0, flg = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			ji++;
		for (; bus.arg[ji] != '\0'; ji++)
		{
			if (bus.arg[ji] > 57 || bus.arg[ji] < 48)
				flg = 1; }
		if (flg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			the_free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE); }
	an = atoi(bus.arg);
	if (bus.lifi == 0)
		the_addnode(head, an);
	else
		the_addqueue(head, an);
}
