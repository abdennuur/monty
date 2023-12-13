#include "monty.h"
/**
 * the_addnode - add node to head stack
 * @head: head of stack
 * @n: new_value
 * Return:
*/
void the_addnode(stack_t **head, int n)
{

	stack_t *nw_nd, *ax;

	ax = *head;
	nw_nd = malloc(sizeof(stack_t));
	if (nw_nd == NULL)
	{ printf("Error\n");
		exit(0); }
	if (ax)
		ax->prev = nw_nd;
	nw_nd->n = n;
	nw_nd->next = *head;
	nw_nd->prev = NULL;
	*head = nw_nd;
}
