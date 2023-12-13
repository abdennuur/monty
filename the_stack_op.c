#include "monty.h"

/**
 * the_mul_nodes - Add top two elements of stack
 * @stack: Ptr to ptr point t top node of stack
 * @line_number: Inte represent line number of opcode.
 */
void the_mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		the_more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sm = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * the_mod_nodes - Add top two elements of stack
 * @stack: ptr to ptr point to top node of stack.
 * @line_number: Int represent line nbr of opcode
 */
void the_mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		the_more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		the_more_err(9, line_number);
	(*stack) = (*stack)->next;
	sm = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
