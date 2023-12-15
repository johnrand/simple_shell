#include "main.h"

/**
 * free_args - frees the memory allocated dynamically
 * @args: freed arguments
 * for the aguments
 *
 * Return: void
 */

void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
