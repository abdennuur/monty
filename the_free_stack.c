#include "monty.h"
/**
* the_free_stack - free doubly linked list
* @head: head of stack
*/
void the_free_stack(stack_t *head)
{
	stack_t *ax;

	ax = head;
	while (head)
	{
		ax = head->next;
		free(head);
		head = ax;
	}
}
