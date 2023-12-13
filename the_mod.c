#include "monty.h"
/**
 * the_mod - compute rest of division of second
 * top element of stack by top element of stack
 * @head: Stack Head
 * @counter: Line Number
 * Return:
*/
void the_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ax = h->next->n % h->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}
