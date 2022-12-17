#include "monty.h"

/**
 * main - main function for monty
 * @argc: numbeer of arguments
 * @argv: opcode file
 * Return: 0
 */


int main(int argc, char **argv)
{
	stack_t *stack;
	stack = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
	read_file(argc[1], &stack);
	free_dlistint(stack);
	return (0);
}
