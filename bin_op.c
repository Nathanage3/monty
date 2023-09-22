#include "monty.h"
/**
 * div_op - div
 * @stack: data struct
 * @line_number: line number
 *
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = temp->prev;
	free(temp);
}
/**
 * add_op - add
 * @stack: stack
 * @line_number: line
 *
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n += temp->n;
	(*stack)->prev = temp->prev;
	free(temp);
}
/**
 * nop_op - nop
 * @stack: struct
 * @line_number: line
 */
void nop_op(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	(void) line_number;
}
/**
 * sub_op - sub
 * @line_number: line
 * @stack: stack
 *
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n -= temp->n;
	(*stack)->prev = temp->prev;
	free(temp);
}
