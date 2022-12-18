#include "monty.h"
/**
 * get_op_func -  checks opcode and selects the correct function
 * @str: the opcode
 *
 * Return: pointer to correct operation function
 */
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
