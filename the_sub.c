#include "monty.h"
/**
  *the_sub - the sustration
  *@head: the stack head
  *@counter: the line_number
  *Return:
 */
void the_sub(stack_t **head, unsigned int counter)
{
	stack_t *ax;
	int subs, nodes;

	ax = *head;
	for (nodes = 0; ax != NULL; nodes++)
		ax = ax->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		the_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ax = *head;
	subs = ax->next->n - ax->n;
	ax->next->n = subs;
	*head = ax->next;
	free(ax);
}
