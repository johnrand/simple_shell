#include "main.h"

/**
 * my_getline - reads a line from stdin
 *
 * Return: void
 */

char *my_getline(void)
{
	char *line;
	static char buffer[MAX_ARGS];
	static size_t index;
	static ssize_t bytesRead;
	size_t lineIndex = 0;

	/**
	 * If the buffer is empty,if we have reached the end of the buffer
	 * read more data
	 */
	if ((size_t)index == (size_t)bytesRead || (size_t)index == MAX_ARGS)
	{
		bytesRead = read(STDIN_FILENO, buffer, MAX_ARGS);
		if (bytesRead <= 0)
		{
			return (NULL);
		}
		index = 0;
	}
	line = malloc(MAX_ARGS);
	if (line == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	/**
	 * Copy characters from the buffer to the line
	 * until a newline character is encountered
	 */
	while ((size_t)index < (size_t)bytesRead && buffer[index] != '\n')
	{
		line[lineIndex++] = buffer[index++];
	}
	line[lineIndex] = '\0';
	if ((size_t)index < (size_t)bytesRead && buffer[index] == '\n')
	{
		index++;
	}
	return (line);
}
