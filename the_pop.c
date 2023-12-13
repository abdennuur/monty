#include "monty.h"
/**
 * the_pop - print the top
 * @head: the stack head
 * @counter: the line_number
 * Return:
*/
void the_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
