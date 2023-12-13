#include "monty.h"
/**
 * the_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void the_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int ln = 0, ax;

	h = *head;
	while (h)
	{
		h = h->next;
		ln++;
	}
	if (ln < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n + h->next->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}
