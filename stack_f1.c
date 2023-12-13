#include "monty.h"


/**
 * the_add_to_stack - Add a node to stack.
 * @new_node: ptr to new node.
 * @ln: Int representing line numberof the opcode.
 */
void the_add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * the_print_stack - Add a node to stack.
 * @stack: Ptr to ptr pointing to top node of stack.
 * @line_number: line nbr of the opcode
 */
void the_print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * the_pop_top - Add a node to stack.
 * @stack: Ptr to ptr pointing to top node of stack
 * @line_number: Int representing line number of the opcode
 */
void the_pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		the_more_err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * the_print_top - Print top node of stack
 * @stack: Ptr to ptr pointing to top node of stack.
 * @line_number: Int representing line number of opcode
 */
void the_print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		the_more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
