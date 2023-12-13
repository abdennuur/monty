#include "monty.h"
/**
 * the_queue - print top
 * @head: the stack head
 * @counter: the line_number
 * Return:
*/
void the_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * the_addqueue - add node to tail stack
 * @n: the new_value
 * @head: the head of stack
 * Return:
*/
void the_addqueue(stack_t **head, int n)
{
	stack_t *nw_nd, *ax;

	ax = *head;
	nw_nd = malloc(sizeof(stack_t));
	if (nw_nd == NULL)
	{
		printf("Error\n");
	}
	nw_nd->n = n;
	nw_nd->next = NULL;
	if (ax)
	{
		while (ax->next)
			ax = ax->next;
	}
	if (!ax)
	{
		*head = nw_nd;
		nw_nd->prev = NULL;
	}
	else
	{
		ax->next = nw_nd;
		nw_nd->prev = ax;
	}
}
