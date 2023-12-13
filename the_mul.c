#include "monty.h"
/**
 * the_mul - multiplie the top two elements of stack
 * @head: the stack head
 * @counter: the line_number
 * Return: 
*/
void the_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->next->n * h->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}
