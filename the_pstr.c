#include "monty.h"
/**
 * the_pstr - print the str starting at top of stack
 * follo by a new line
 * @head: the stack head
 * @counter: the line_number
 * Return:
*/
void the_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
