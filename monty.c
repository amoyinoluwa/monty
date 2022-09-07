#include "monty.h"

int main(int argc, char** argv)
{
	FILE *fp;
	char *command, *chars;
	size_t buf_size;
	int line_number = 1;
	stack_t *buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
	}
	fp = fopen(argv[1], 'r');
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&chars, &buf_size, fp) != EOF)
	{
		command = strtok(chars, " \r\t\n");
		get_function(buffer, line_number);
		line_number++;
	}
	return (0);
}
