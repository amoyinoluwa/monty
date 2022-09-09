#include "monty.h"

fileStream file;

/**
 * main - main function to read bytecode
 * @argc: number of arguments in command line
 * @argv: pointer to args
 * Return: 0
 */

int main(int argc, char **argv)
{
	
	char *command;
	size_t buf_size;
	unsigned int line_number = 1;

	file.chars = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file.fp = fopen(argv[1], "r");
	if (file.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&file.chars, &buf_size, file.fp) != EOF)
	{
		command = strtok(file.chars, " \r\t\n");
		if (command[0] != '#')
		{
			get_function(command, &file.buffer, line_number);
		}
		line_number++;
	}
	free_mem();
	return (0);
}
