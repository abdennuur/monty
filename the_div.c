#include "monty.h"
/**
 * the_f_div - divide top two elements of stack
 * @head: stack
 * @counter: line_number
 * Return:
*/
void the_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	ax = h->next->n / h->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}
