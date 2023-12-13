#include "monty.h"

/**
 * the_nop - nothing
 * @stack: Ptr to ptr pointing to top node of stack
 * @line_number: Int representing line number of the opcode
 */
void the_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * the_swap_nodes - Swap top two elements of stack
 * @stack: Ptr to ptr pointing to top node of stack
 * @line_number: Int representing line number ofe opcode
 */
void the_swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		the_more_err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * the_add_nodes - Add top two elements of stack
 * @stack: ptr to ptr pointing to top node of stack
 * @line_number: Int representing line nbr of opcode
 */
void the_add_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		the_more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sm = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * the_sub_nodes - Add top two elements of stack
 * @stack: Ptr to ptr pointing to top node of stack
 * @line_number: Int representing line number of  opcode.
 */
void the_sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		the_more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sm = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * the_div_nodes - Add top two elements of stack
 * @stack: Ptr to ptr pointing to top node of stack
 * @line_number: Int representing line nbr othe opcode
 */
void the_div_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		the_more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		the_more_err(9, line_number);
	(*stack) = (*stack)->next;
	sm = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
