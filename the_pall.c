#include "monty.h"
/**
 * the_pall - print stack
 * @head: the stack head
 * @counter:
 * Return:
*/
void the_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
