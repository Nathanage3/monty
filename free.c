#include "monty.h"
/**
 * free_stack - free
 * @stack: struct
 *
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
