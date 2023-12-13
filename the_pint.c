#include "monty.h"
/**
 * the_pint - print the top
 * @head: the stack head
 * @counter: the line_number
 * Return:
*/
void the_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
