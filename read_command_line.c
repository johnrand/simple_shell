#include "main.h"

/**
 * read_command_line - read line of input from user
 * Descrption: reads line of input and returns
 *
 * Return: line read
 */

char *read_command_line(void)
{
	char *line_to_read = NULL;
	size_t bufsize = 0;
	ssize_t read_chars;

	read_chars = getline(&line_to_read, &bufsize, stdin);

	/* check for EOF condition (CTRL + D) */

	if (read_chars == -1)
	{
		free(line_to_read);
		return (NULL);
	}

	return (line_to_read);
}
