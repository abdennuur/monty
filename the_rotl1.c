#include "monty.h"
/**
  *the_rotl- rotate the stack to top
  *@head: the stack head
  *@counter: the line_number
  *Return:
 */
void the_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *ax;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	ax = (*head)->next;
	ax->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = ax;
}
