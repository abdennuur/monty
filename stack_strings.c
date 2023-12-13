#include "monty.h"

/**
 * the_print_char - Print Ascii value
 * @stack: Ptr to ptr pointing to top node of stack
 * @line_number: Int representing line nbr of opcode
 */
void the_print_char(stack_t **stack, unsigned int line_number)
{
	int aski;

	if (stack == NULL || *stack == NULL)
		the_string_err(11, line_number);

	aski = (*stack)->n;
	if (aski < 0 || aski > 127)
		the_string_err(10, line_number);
	printf("%c\n", aski);
}

/**
 * the_print_str - Print str
 * @stack: ptr to ptr pointing to top node of stack
 * @ln: Int representing line number ofopcode.
 */
void the_print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int aski;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		aski = temp->n;
		if (aski <= 0 || aski > 127)
			break;
		printf("%c", aski);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * the_rotl - Rotate first node of stack to bottom
 * @stack: Ptr to ptr pointing to top node of stack
 * @ln: Int representing line nbr of of opcode
 */
void the_rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * the_rotr - Rotate last node of stack to  top
 * @stack: Ptr to ptr pointing to top node of stack
 * @ln: Int representing the line nbr ofthe opcode
 */
void the_rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
