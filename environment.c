#include "main.h"

/**
 * print_enviroment - print the shells environment
 *
 * Return: void
 */

void print_enviroment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
