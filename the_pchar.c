#include "monty.h"
/**
 * the_pchar - print the char at top of stack
 * follow by  new line
 * @head: the stack head
 * @counter: the line_number
 * Return:
*/
void the_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
