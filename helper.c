#include "monty.h"
/**
 * mod_op - mod
 * @stack: struct
 * @line_number: line number
 *
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n %= temp->n;
	(*stack)->prev = temp->prev;
	free(temp);
}
/**
 * pchar_op - pchar
 * @stack: stack
 * @line_number: line
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_value);
	putchar('\n');
}
/**
 * mul_op - mul
 * @stack: struct
 * @line_number: line
 *
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = temp->prev;
	free(temp);
}
/**
 * rotl_op - rotl
 * @stack: struct
 * @line_number: line
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = (*stack)->prev;
	(*stack)->prev->prev = temp;
	(*stack)->prev->next = NULL;
}
/**
 * pstr_op - pstr
 * @stack: struct
 * @line_number: line
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n >= 128)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
