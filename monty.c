#include "monty.h"
/**
 * read_file - read a bytecode file and run command
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
*/

void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_fun s;
	int read;
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file))) != -1)
	{
		line  = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_coutn++;
			continue;
		}

	}
}
