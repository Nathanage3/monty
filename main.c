#include "monty.h"
/**
 * main - Entry
 * @argc: argc
 * @argv: argv
 * Return: always 0
 */
global_vars_t globals;
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		process_line(line, line_number, &stack);
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
/**
 * process_line - process line
 * @line: line
 * @line_number: line_number
 * @stack: data structure
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode = NULL, *arg = NULL;
	void (*func)(stack_t **, unsigned int);

	opcode = strtok(line, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return;
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n\t");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		globals.value = atoi(arg);
	}
	func = get_op_func(opcode);
	if (func != NULL)
	{
		func(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
